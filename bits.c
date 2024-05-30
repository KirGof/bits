#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t sign;
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
} bits;

void set_data(bits *data)
{
    long long buff = 0;
    int count_arg = scanf("%llu", &buff);
    if (count_arg != 1)
    {
        printf("Enter one number.");
    }
    else
    {
        if (buff < 0)
        {
            data->sign = 1;
            buff = -buff;
        }

        unsigned long long mask = 1;
        int position_major_bit = 0;
        for (int i = 1; i < 65; i++)
        {
            if (buff & mask)
            {
                position_major_bit = i;
            }
            mask <<= 1;
        }
        if (position_major_bit > 32)
        {
            data->d = buff;
        }
        else if (position_major_bit > 16 && position_major_bit <= 32)
        {
            data->c = buff;
        }
        else if (position_major_bit > 8 && position_major_bit <= 16)
        {
            data->b = buff;
        }
        else if (position_major_bit <= 8)
        {
            data->a = buff;
        }
    }
}

void printing_struct(bits *data)
{
    printf("sign %d\n", data->sign);
    printf("uint8_t %u\n", data->a);
    printf("uint16_t %u\n", data->b);
    printf("uint32_t %u\n", data->c);
    printf("uint64_t %lu\n", data->d);
}

void add_arr_64_bit(bits *data)
{
    char arr[65] = {0};
    unsigned long long mask = 1;
    mask <<= 63;
    for (int i = 0; i < 64; i++)
    {
        if (data->d & mask)
        {
            arr[i] = '1';
        }
        else
        {
            arr[i] = '0';
        }
        mask >>= 1;
    }
    printf("%s\n", arr);
}

void add_arr_32_bit(bits *data)
{
    char arr[33] = {0};
    unsigned long long mask = 1;
    mask <<= 31;
    for (int i = 0; i < 32; i++)
    {
        if (data->c & mask)
        {
            arr[i] = '1';
        }
        else
        {
            arr[i] = '0';
        }
        mask >>= 1;
    }
    printf("%s\n", arr);
}

void add_arr_16_bit(bits *data)
{
    char arr[17] = {0};
    unsigned long long mask = 1;
    mask <<= 15;
    for (int i = 0; i < 16; i++)
    {
        if (data->b & mask)
        {
            arr[i] = '1';
        }
        else
        {
            arr[i] = '0';
        }
        mask >>= 1;
    }
    printf("%s\n", arr);
}

void add_arr_8_bit(bits *data)
{
    char arr[9] = {0};
    unsigned long long mask = 1;
    mask <<= 7;
    for (int i = 0; i < 8; i++)
    {
        if (data->a & mask)
        {
            arr[i] = '1';
        }
        else
        {
            arr[i] = '0';
        }
        
        mask >>= 1;
    }

    printf("%s\n", arr);
}

void printing_on_bits(bits *data)
{
    if (data->d > 0)
    {
        add_arr_64_bit(data);
    }
    else if (data->c > 0)
    {
        add_arr_32_bit(data);
    }
    else if (data->b > 0)
    {
        add_arr_16_bit(data);
    }
    else if (data->a > 0)
    {
        add_arr_8_bit(data);
    }
}

int main()
{
    bits data = {0};
    set_data(&data);
    // printing_struct(&data);
    printing_on_bits(&data);
    
    return 0;
}
