#include <stdint.h>
#include <stdio.h>

void OutputBin(uint64_t input)
{
	uint8_t temp[65] = {0};  
	int i = 0;
	while(input)
	{
		temp[i] = input % 2;	//取余数存放到数组中，此为得到的二进制数
		input = (uint64_t)input / 2;  //短除，while中判断是否除尽
		i++;  //存储了一个二进制数，自加存储下一个
	}
	for(i = 33; i>=0; i--)  //由于最后一次input为0无效，i还是自加了，因此最后一次自加的值是无用的，所以先自减，然后将余数从后往前读取
    {
		printf("%d",temp[i]);
	}
	printf("\r\n");
}

int num_of_turn(int64_t cards){
    OutputBin(cards);
    int num = 0;
    int64_t mask = ~(int64_t)0 << 34;
    uint64_t turn_mask = 0x600000000;
    while(cards){
        while(!(cards & mask)){
            mask >>= 1;
            turn_mask >>= 1;
        }
        cards ^= turn_mask;
        OutputBin(cards);
        num++;
        mask >> 1;
        turn_mask >> 1;
    }
    return num;
}

int main(void){
    printf("反转次数：%d\n", num_of_turn(0x100F0F00));
    return 0;
}