dtb-y += exynos7870-a3xpremiumlte_jpn_dcm_02.dtb
dtb-y += exynos7870-a3xpremiumlte_jpn_dcm_03.dtb
dtb-y += exynos7870-a3xpremiumlte_jpn_dcm_04.dtb
dtb-y += exynos7870-a3xpremiumlte_jpn_dcm_05.dtb
dtb-y += exynos7870-a3xpremiumlte_jpn_dcm_06.dtb
dtb-y += exynos7870-a3xpremiumlte_jpn_dcm_07.dtb

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)

ifeq ($(CONFIG_EXYNOS_DTBTOOL),y)
targets += dtb.img

DTB_OBJS += $(shell find -L $(obj)/dts/ -name \*.dtb)

$(obj)/dtb.img: $(DTB_OBJS) FORCE
	$(call if_changed,dtbtool_exynos)
endif

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
