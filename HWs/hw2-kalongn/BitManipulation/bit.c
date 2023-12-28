#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief should give the bit value in num at position pos.
 * 		   a. Example GetBit( 12, 2) should return 1.
 *
 * @param num
 * 		a signed integer.
 * @param pos
 * 		a signed integer indicating position (0-indexed).
 * @return an int that indicate the bit at the pos of num.
 */
int GetBit(int num, int pos)
{
	return num & (1 << pos) ? 1 : 0;
}

/**
 * @brief should set the bit in num at position pos.
 *  	  	a. Explanation :- if K-th bit is 0, then set it to 1 and if it is 1 then leave it unchanged.
 *
 * @param num
 * 		a signed integer.
 * @param pos
 * 		a signed integer indicating position (0-indexed).
 * @return the new integer value if the pattern is changed.
 */
int SetBit(int num, int pos)
{
	num |= (1 << pos);
	return num;
}

/**
 * @brief should clear the bit in num at position pos.
 *
 * @param num
 * 		a signed integer.
 * @param pos
 * 		a signed integer indicating position (0-indexed).
 * @return the new integer value.
 */
int ClearBit(int num, int pos)
{
	num &= ~(1 << pos);
	return num;
}

/**
 * @brief should reverse the bit pattern of num.
 *
 * @param num
 * 		a signed integer.
 * @return the new integer value.
 */
int Reversbit(int num)
{
	int result = 0, numBits = sizeof(num) * 8;
	for (int i = 0; i < numBits; i++)
	{
		if (num & (1 << i))
		{
			result = result | (1 << (numBits - 1 - i));
		}
	}
	return result;
}

/**
 * @brief should give the number of ones in num.
 *
 * @param num
 * 		a signed integer.
 * @return the amount of ones in num's binary representation.
 */
int CountBit(int num)
{
	int count = 0;
	while (num)
	{
		num &= (num - 1);
		count++;
	}
	return count;
}

/**
 * @brief determine if a number is power of 2.
 *
 * @param num
 * 		a  unsigned integer.
 * @return 1 if num is power of 2 else 0.
 */
int PowerofTwo(unsigned int num)
{
	if (num == 0)
	{
		return num;
	}
	return (num & (num - 1)) == 0;
}

/**
 * @brief A rotation (or  circular  shift) is an operation similar to shift except that
 *        the bits that fall off at one end are put back to the other end.
 * 		  In left rotation, the bits that fall off at the left end are put back at the right end.
 * @param num
 * 		a signed integer.
 * @param pos
 * 		a unsigned integer indicating position (0-indexed).
 * @return the integer value of the rotated binary.
 */
int RotateLeft(int num, unsigned int pos)
{
	while (pos)
	{
		if (num < 0)
		{
			num = (num << 1) + 1;
		}
		else
		{
			num = num << 1;
		}
		pos--;
	}
	return num;
}

/**
 * @brief A rotation (or  circular  shift) is an operation similar to shift except that
 *        the bits that fall off at one end are put back to the other end.
 * 		   In right rotation, the bits that fall off at the right end are put back at the left end.
 * @param num
 * 		a signed integer.
 * @param pos
 * 		an unsigned integer indicating position (0-indexed).
 * @return the integer value of the rotated binary.
 */
int RotateRight(int num, unsigned int pos)
{
	while (pos)
	{
		if (num & 1)
		{
			num = num >> 1;
			num = SetBit(num, 31);
		}
		else
		{
			num = (int)((unsigned)num >> 1);
		}
		pos--;
	}
	return num;
}

/**
 * @brief convert 'string' that should be a numerical value to a integer.
 *
 * @param str
 * 		the 'string' of characters (Should be number with the 0 index can potentially represent the sign of the number).
 * @return the integer value of the given 'string'.
 */
int myAtoi(char *str)
{
	int result = 0, sign = 1, index = 0;
	if (str[0] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[0] == '+')
	{
		index++;
	}

	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
		{
			break;
		}
		result = result * 10 + (str[index] - '0');
		index++;
	}

	return sign * result;
}

int main(int argc, char *argv[])
{

	if (argc <= 1)
	{
		printf("Not Enough Arguments");
		return 1;
	}

	switch (myAtoi(argv[1]))
	{
	case 1:
	case 2:
	case 3:
	case 7:
	case 8:
		if (argc <= 3)
		{
			printf("Not Enough Arguments");
			return 1;
		}
		break;
	case 4:
	case 5:
	case 6:
		if (argc <= 2)
		{
			printf("Not Enough Arguments");
			return 1;
		}
		break;
	default:
		printf("No Such Arguments");
		return 1;
	}

	int result = 0;
	switch (myAtoi(argv[1]))
	{
	case 1:
		result = GetBit(myAtoi(argv[2]), myAtoi(argv[3]));
		break;
	case 2:
		result = SetBit(myAtoi(argv[2]), myAtoi(argv[3]));
		break;
	case 3:
		result = ClearBit(myAtoi(argv[2]), myAtoi(argv[3]));
		break;
	case 4:
		result = Reversbit(myAtoi(argv[2]));
		break;
	case 5:
		result = CountBit(myAtoi(argv[2]));
		break;
	case 6:
		result = PowerofTwo(myAtoi(argv[2]));
		break;
	case 7:
		result = RotateLeft(myAtoi(argv[2]), myAtoi(argv[3]));
		break;
	case 8:
		result = RotateRight(myAtoi(argv[2]), myAtoi(argv[3]));
		break;
	default:
		printf("An error occurs, please double check your answer.");
		return 1;
	}
	printf("result: %d \n", result);

	return result;
}