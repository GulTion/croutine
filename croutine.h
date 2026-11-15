int cro_main(void *fn, ...);
#define cro(fn, ...) cro_main((void *)(fn), ##__VA_ARGS__)
