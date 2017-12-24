#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct pair {
	int idx;
	int val;
};

static int cmp(const void *a, const void *b)
{
	return ((struct pair *)a)->val - ((struct pair *)b)->val;
}

int* twoSum(int* nums, int numsSize, int target) {
	int *result = malloc(sizeof(int) * 2);
	struct pair *pairs = (struct pair*) malloc(sizeof(struct pair) * numsSize);
	int pf, pb, i;
	pf = 0;
	pb = numsSize - 1;

	for (i = 0; i < numsSize; i++) {
		pairs[i].idx = i;
		pairs[i].val = nums[i];
	}
	qsort((void *)pairs, numsSize, sizeof(struct pair), cmp);

	while (pf < pb) {
		int sum = pairs[pf].val + pairs[pb].val;
		printf("pf=%d pb=%d sum=%d t=%d\n", pf, pb, sum, target);
		if (sum < target)
			pf++;
		else if (sum > target)
			pb--;
		else {
			result[0] = pairs[pf].idx;
			result[1] = pairs[pb].idx;
			return result;
		}
	}
	result[0] = 0;
	result[1] = 0;
	return result;
}


int main()
{
//	int arr[] = {2, 7, 19, 15, 11, 22, 21, 31, 23, 64, 52};
	int arr[] = {-3, 4, 3, 90};
	int *r;

//	printf("%ld\n", sizeof(arr)/sizeof(int));
	r = twoSum(arr, sizeof(arr)/sizeof(int), 0);
	printf("[%d, %d] = %d %d\n", r[0], r[1], arr[r[0]], arr[r[1]]);
	/*
	r = twoSum(arr, sizeof(arr)/sizeof(int), 54);
	printf("[%d, %d] = %d %d\n", r[0], r[1], arr[r[0]], arr[r[1]]);
	r = twoSum(arr, sizeof(arr)/sizeof(int), 45);
	printf("[%d, %d] = %d %d\n", r[0], r[1], arr[r[0]], arr[r[1]]);
	r = twoSum(arr, sizeof(arr)/sizeof(int), 40);
	printf("[%d, %d] = %d %d\n", r[0], r[1], arr[r[0]], arr[r[1]]);
*/
	return 0;
}
