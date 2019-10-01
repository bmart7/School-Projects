#include "/user/cse320/Projects/project05.support.h"
#include <stdbool.h>
#include <math.h>
#define NULL 0

bool validBase(const char val[], int base)
{

  int count = 0;
  int size = 0;
	while (val[size] != NULL)
	{
		size++;
	}
  bool start = false;
  for (int i = 0; i < size; i++)
  {

		if ((val[i] == ' ' || val[i] == '-' || val[i] == '+') && !start)
		{
			
		}
    else if (val[i] >= '0' && val[i] <= '9')
    {
      if ((val[i] - '0') < base)
			{
				count++;
				start = true;
			}
			else
			{
				break;
			}
    }
    else if (val[i] >= 'a' && val[i] <= 'z')
    {
      if ((val[i] - 'a' + 10) < base)
      {
        count++;
				start = true;
      }
      else
      {
        break;
      }
    }
    else if (val[i] >= 'A' && val[i] <= 'Z')
    {
      if ((val[i] - 'A' + 10) < base)
			{
				count++;
				start = true;
			}
			else
			{
				break;
			}
    }
		else
		{
			break;
		}
  }

  if (count > 0)
  {
    return true;
  }
  return false;

}

int toInt(const char val[], int base)
{
  int size= 0;
	while (val[size] != NULL)
	{
		size++;
	}
  char temp[size];
  bool negative = false;
  bool start = false;
  int iter = 0;
  for (int i = 0; i < size; i++)
  {

		if ((val[i] == ' ' || val[i] == '+') && !start)
   	{
      	;
   	}
		else if(val[i] == '-' && !start)
		{
			negative = true;
		}
    else if (val[i] >= '0' && val[i] <= '9')
    {
			if ((val[i] - '0') < base)
			{
      	temp[iter] = val[i];
      	iter++;
				start = true;
			}
			else
			{
				break;
			}
    }
    else if (val[i] >= 'A' && val[i] <= 'Z')
    {
			if ((val[i] - 'A' + 10) < base)
			{
				temp[iter] = val[i];
				iter++;
				start = true;
			}
			else
			{
				break;
			}
		}
		else if (val[i] >= 'a' && val[i] <= 'z')
		{
			if ((val[i] - 'a' + 10) < base)
			{
				temp[iter] = val[i];
				iter++;
				start = true;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
  }
	
  int j = iter-1;
	int result = 0;
	for (int i = 0; i < iter; i++)
	{
		if (temp[i] >= '0' && temp[i] <= '9')
		{
			result += (temp[i] - '0') * pow(base, j);
		}
		else if (temp[i] >= 'A' && temp[i] <= 'Z')
		{
			result += (temp[i] - 'A' + 10) * pow(base, j);
		}
		else if (temp[i] >= 'a' && temp[i] <= 'z')
		{
			result += (temp[i] - 'a' + 10) * pow(base, j);
		}
		j--;
	}

	if (negative)
	{
		result *= -1;
	}

	return result;

}

int convert(const char val[], int base, int* loc)
{

  if (base <= 2 || base >= 32 || ! validBase(val, base))
  {
    return 0;
  }

  *loc = toInt(val, base);

}

