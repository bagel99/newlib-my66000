%C%_src = \
	%D%/s_fabs.c %D%/s_sqrt.c \
	%D%/s_log.c %D%/s_log10.c %D%/s_log2.c %D%/s_log1p.c \
	%D%/s_exp.c %D%/s_exp10.c %D%/s_exp2.c \
	%D%/s_sin.c %D%/s_cos.c %D%/s_tan.c \
	%D%/s_asin.c %D%/s_acos.c %D%/s_atan.c %D%/s_atan2.c \
	%D%/s_fabsf.c %D%/s_sqrtf.c \
	%D%/s_logf.c %D%/s_log10f.c %D%/s_log2f.c %D%/s_log1pf.c \
	%D%/s_expf.c %D%/s_exp10f.c %D%/s_exp2f.c \
	%D%/s_sinf.c %D%/s_cosf.c %D%/s_tanf.c \
	%D%/s_asinf.c %D%/s_acosf.c %D%/s_atanf.c %D%/s_atan2f.c

libm_a_SOURCES += $(%C%_src)

