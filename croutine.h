int cro_main(void *fn, ...);
#define cro(fn, ...) cro_main((void *)(fn), ##__VA_ARGS__)

void cro_yield(void);
void cro_init(void);
void cro_join(void);
