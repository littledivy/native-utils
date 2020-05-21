#include <time.h>


#include <stdint.h>

#define DEADBEEF_MAX UINT32_MAX

/* Dead Beef Random Number Generator
 * From: http://inglorion.net/software/deadbeef_rand
 * A fast, portable psuedo-random number generator by BJ Amsterdam Zuidoost.
 * Stated in license terms: "Feel free to use the code in your own software." */

/* Generates a random number between 0 and DEADBEEF_MAX. */
uint32_t deadbeef_rand(void);

/* Seeds with the given integer. */
void deadbeef_srand(uint32_t x);

/* Generates seed from the current time. */
uint32_t deadbeef_generate_seed(void);

/* Seeds with the above function. */
#define deadbeef_srand_time() deadbeef_srand(deadbeef_generate_seed())

/* Returns random double in the range [a, b).
 * Taken directly from the rand() man page. */
#define DEADBEEF_UNIFORM(a, b) \
	((a) + (deadbeef_rand() / (((double)DEADBEEF_MAX / (b - a) + 1))))

/* Returns random integer in the range [a, b).
 * Also taken from the rand() man page. */
#define DEADBEEF_RANDRANGE(a, b) \
	(uint32_t)DEADBEEF_UNIFORM(a, b)


static uint32_t deadbeef_seed;
static uint32_t deadbeef_beef = 0xdeadbeef;

uint32_t deadbeef_rand(void)
{
	deadbeef_seed = (deadbeef_seed << 7) ^ ((deadbeef_seed >> 25) + deadbeef_beef);
	deadbeef_beef = (deadbeef_beef << 7) ^ ((deadbeef_beef >> 25) + 0xdeadbeef);
	return deadbeef_seed;
}

void deadbeef_srand(uint32_t x)
{
	deadbeef_seed = x;
	deadbeef_beef = 0xdeadbeef;
}

/* Taken directly from the documentation:
 * http://inglorion.net/software/cstuff/deadbeef_rand/ */
uint32_t deadbeef_generate_seed(void)
{
	  uint32_t t = (uint32_t)time(NULL);
	  uint32_t c = (uint32_t)clock();
	  return (t << 24) ^ (c << 11) ^ t ^ (size_t) &c;
}
