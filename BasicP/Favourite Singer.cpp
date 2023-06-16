#include <stdio.h> 
#include <stdint.h> 
#define MAX_SINGERS 100001 
typedef struct {     
	int64_t singer;     
	int64_t count; 
	} 
	SingerCount; 
int main() {     
	int64_t n;     
	if (scanf("%ld", &n) != 1) {         
		printf("Invalid input\n");         
		return 1;     
		}     
		if (n < 1 || n > 1000000) {         
			printf("Invalid input\n");         
			return 1;     
		}     
		SingerCount singerCounts[MAX_SINGERS] = {0};     
		int64_t maxCount = 0;     
		for (int64_t i = 0; i < n; i++) {         
			int64_t singer;         
			if (scanf("%ld", &singer) != 1) {             
				printf("Invalid input\n");             
				return 1;         
			}         
			if (singer < 1 || singer > 100000) {             
				printf("Invalid input\n");            
				return 1;         
				}         
				singerCounts[singer].singer = singer;         
				singerCounts[singer].count++;         
				if (singerCounts[singer].count > maxCount) {             
					maxCount = singerCounts[singer].count;         
					}     
					}    
				int64_t favoriteSingers = 0;     
				for (int64_t i = 1; i < MAX_SINGERS; i++) {         
					if (singerCounts[i].count == maxCount) {             
						favoriteSingers++;         
						}     
					}     
					printf("%ld\n", favoriteSingers);     
					return 0; 
					}