#!/bin/bash
# kernel build script by Tkkg1994 v0.4 (optimized from apq8084 kernel source)
# Modified by djb77 / XDA Developers

# ---------
# VARIABLES
# ---------
BUILD_SCRIPT=2.34
VERSION_NUMBER=0.1.0
ARCH=arm64
BUILD_CROSS_COMPILE=/opt/toolchains/google/aarch64-linux-android-4.9/bin/aarch64-linux-android-
BUILD_JOB_NUMBER=`grep processor /proc/cpuinfo|wc -l`
RDIR=$(pwd)
OUTDIR=$RDIR/arch/$ARCH/boot
DTSDIR=$RDIR/arch/$ARCH/boot/dts
DTBDIR=$OUTDIR/dtb
DTCTOOL=$RDIR/scripts/dtc/dtc
INCDIR=$RDIR/include
PAGE_SIZE=2048
DTB_PADDING=0
KERNELNAME=TKernel
KERNELCONFIG=exynos7870-a3xpremiumlte_jpn_dcm_defconfig

# ---------
# FUNCTIONS
# ---------
FUNC_CLEAN()
{
echo ""
echo "Deleting old work files"
echo ""
make -s clean
make -s ARCH=arm64 distclean
rm -f $RDIR/*.img
rm -f $RDIR/*.zip
rm -f $RDIR/*.log
rm -rf $RDIR/arch/arm64/boot/dtb
rm -f $RDIR/arch/$ARCH/boot/dts/*.dtb
rm -f $RDIR/arch/$ARCH/boot/boot.img-dtb
rm -f $RDIR/arch/$ARCH/boot/boot.img-zImage
rm -f $RDIR/ramdisk/image-new.img
rm -f $RDIR/ramdisk/ramdisk-new.cpio.gz
rm -f $RDIR/ramdisk/image-new.img
rm -f $RDIR/ramdisk/split_img/boot.img-zImage
rm -f $RDIR/ramdisk/zip/sc04j-jpn.img
echo "" > $RDIR/ramdisk/ramdisk/acct/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/cache/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/data/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/dev/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/mnt/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/proc/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/storage/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/sys/.gitkeep
echo "" > $RDIR/ramdisk/ramdisk/system/.gitkeep
}

FUNC_DELETE_gitkeep()
{
find . -name \.gitkeep -type f -delete
}

FUNC_BUILD_ZIMAGE()
{
echo "Loading configuration"
echo ""
make -s -j$BUILD_JOB_NUMBER ARCH=$ARCH \
	CROSS_COMPILE=$BUILD_CROSS_COMPILE \
	$KERNEL_DEFCONFIG || exit -1
echo ""
echo "Compiling zImage"
echo ""
make -s -j$BUILD_JOB_NUMBER ARCH=$ARCH \
	CROSS_COMPILE=$BUILD_CROSS_COMPILE || exit -1
echo ""
}

FUNC_BUILD_DTB()
{
[ -f "$DTCTOOL" ] || {
	echo "You need to run ./build.sh first!"
	exit 1
}
case $MODEL in
SC04J)
	DTSFILES="exynos7870-a3xpremiumlte_jpn_dcm_02 exynos7870-a3xpremiumlte_jpn_dcm_03
		exynos7870-a3xpremiumlte_jpn_dcm_04 exynos7870-a3xpremiumlte_jpn_dcm_05
		exynos7870-a3xpremiumlte_jpn_dcm_06 exynos7870-a3xpremiumlte_jpn_dcm_07"
	;;
*)
	echo "Unknown device: $MODEL"
	exit 1
	;;
esac
mkdir -p $OUTDIR $DTBDIR
cd $DTBDIR || {
	echo "Unable to cd to $DTBDIR!"
	exit 1
}
rm -f ./*
echo ""
echo "Processing dts files"
echo ""
for dts in $DTSFILES; do
	echo "=> Processing: ${dts}.dts"
	${CROSS_COMPILE}cpp -nostdinc -undef -x assembler-with-cpp -I "$INCDIR" "$DTSDIR/${dts}.dts" > "${dts}.dts"
	echo "=> Generating: ${dts}.dtb"
	$DTCTOOL -p $DTB_PADDING -i "$DTSDIR" -O dtb -o "${dts}.dtb" "${dts}.dts"
done
echo ""
echo "Generating dtb.img"
echo ""
$RDIR/scripts/dtbTool/dtbTool -o "$OUTDIR/dtb.img" -d "$DTBDIR/" -s $PAGE_SIZE
}

FUNC_BUILD_RAMDISK()
{

if [ ! -f "$RDIR/ramdisk/ramdisk/config" ]; then
	mkdir $RDIR/ramdisk/ramdisk/config
	chmod 500 $RDIR/ramdisk/ramdisk/config
fi

mv $RDIR/arch/$ARCH/boot/Image $RDIR/arch/$ARCH/boot/boot.img-zImage
mv $RDIR/arch/$ARCH/boot/dtb.img $RDIR/arch/$ARCH/boot/boot.img-dtb
case $MODEL in
SC04J)
	rm -f $RDIR/ramdisk/split_img/boot.img-zImage
	rm -f $RDIR/ramdisk/split_img/boot.img-dtb
	mv -f $RDIR/arch/$ARCH/boot/boot.img-zImage $RDIR/ramdisk/split_img/boot.img-zImage
	mv -f $RDIR/arch/$ARCH/boot/boot.img-dtb $RDIR/ramdisk/split_img/boot.img-dtb
	cd $RDIR/ramdisk/
	./repackimg.sh
	echo SEANDROIDENFORCE >> image-new.img
	;;
*)
	echo "Unknown device: $MODEL"
	exit 1
	;;
esac
}

FUNC_BUILD_BOOTIMG()
{
	FUNC_CLEAN
	FUNC_DELETE_gitkeep
	(
	FUNC_BUILD_ZIMAGE
	FUNC_BUILD_DTB
	FUNC_BUILD_RAMDISK
	) 2>&1	 | tee -a $RDIR/build.log
}

FUNC_BUILD_ZIP()
{
echo ""
echo "Building Zip File"
cd $ZIP_FILE_DIR
zip -gq $ZIP_NAME -r META-INF/ -x "*~"
zip -gq $ZIP_NAME -r system/ -x "*~"
[ -f "$RDIR/sc04j-jpn.img" ] && mv $RDIR/sc04j-jpn.img $ZIP_FILE_DIR && zip -gq $ZIP_NAME sc04j-jpn.img -x "*~"
chmod a+r $ZIP_NAME
mv -f $ZIP_FILE_TARGET $RDIR/$ZIP_NAME
cd $RDIR
}

OPTION_1()
{
rm -f $RDIR/build.log
MODEL=SC04J
KERNEL_DEFCONFIG=$KERNELCONFIG
START_TIME=`date +%s`
	(
	FUNC_BUILD_BOOTIMG
	) 2>&1	 | tee -a $RDIR/build.log
mv -f $RDIR/ramdisk/image-new.img $RDIR/sc04j-jpn.img
mv -f $RDIR/build.log $RDIR/build-sc04j.log
END_TIME=`date +%s`
let "ELAPSED_TIME=$END_TIME-$START_TIME"
echo ""
echo "Total compiling time is $ELAPSED_TIME seconds"
echo ""
echo "You can now find your sc04j-jpn.img in the build folder"
echo "You can now find your build-sc04j.log file in the build folder"
echo ""
exit
}

OPTION_4()
{
rm -f $RDIR/build.log
MODEL=SC04J
KERNEL_DEFCONFIG=$KERNELCONFIG
START_TIME=`date +%s`
	(
	FUNC_BUILD_BOOTIMG
	) 2>&1	 | tee -a $RDIR/build.log
mv -f $RDIR/ramdisk/image-new.img $RDIR/sc04j-jpn.img
mv -f $RDIR/build.log $RDIR/build-sc04j.log
ZIP_DATE=`date +%Y%m%d`
ZIP_FILE_DIR=$RDIR/ramdisk/zip
ZIP_NAME=TKernel_SC04J_v$VERSION_NUMBER.zip
ZIP_FILE_TARGET=$ZIP_FILE_DIR/$ZIP_NAME
FUNC_BUILD_ZIP
END_TIME=`date +%s`
let "ELAPSED_TIME=$END_TIME-$START_TIME"
echo ""
echo "Total compiling time is $ELAPSED_TIME seconds"
echo ""
echo "You can now find your .zip file in the build folder"
echo "You can now find your build-sc04j.log file in the build folder"
echo ""
exit
}

OPTION_0()
{
FUNC_CLEAN
exit
}

# ----------------------------------
# CHECK COMMAND LINE FOR ANY ENTRIES
# ----------------------------------
if [ $1 == 0 ]; then
	OPTION_0
fi
if [ $1 == 1 ]; then
	OPTION_1
fi
if [ $1 == 4 ]; then
	OPTION_4
fi

# -------------
# PROGRAM START
# -------------
rm -rf ./build.log
clear
echo "TKernel Build Script v$BUILD_SCRIPT -- Kernel Version: v$VERSION_NUMBER"
echo ""
echo " 0) Clean Workspace"
echo ""
echo " 1) Build SuperKernel boot.img for SC04J"
echo " 4) Build SuperKernel boot.img and .zip for SC04J"
echo ""
echo " 9) Exit"
echo ""
read -p "Please select an option " prompt
echo ""
if [ $prompt == "0" ]; then
	OPTION_0
elif [ $prompt == "1" ]; then
	OPTION_1
elif [ $prompt == "4" ]; then
	OPTION_4
elif [ $prompt == "9" ]; then
	exit
fi

