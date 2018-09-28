dtb-$(CONFIG_MACH_EXYNOS7870_A3XPREMIUMLTE_JPN_DCM) := \
	exynos7870-a3xpremiumlte_jpn_dcm_02.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_03.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_04.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_05.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_06.dtb \
	exynos7870-a3xpremiumlte_jpn_dcm_07.dtb

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
