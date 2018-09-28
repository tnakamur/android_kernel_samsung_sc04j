dtb-$(CONFIG_MACH_EXYNOS7870_A3XPREMIUMLTE_JPN_DCM) := \
	exynos7870-a3xpremiumlte_jpn_dcm_02.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_03.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_04.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_05.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_06.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_07.dtb

targets += dtbs

DTB_NAMES := $(subst $\",,$(CONFIG_BUILD_ARM64_APPENDED_DTB_IMAGE_NAMES))
ifneq ($(DTB_NAMES),)
DTB_LIST := $(addsuffix .dtb,$(DTB_NAMES))
else
DTB_LIST := $(dtb-y)
endif
targets += $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := dts/*.dtb *.dtb
