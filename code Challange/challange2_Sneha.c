#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct my_date_t
{
    uint8_t date;
    uint8_t month;
    uint16_t year;
} my_date_t;

typedef enum status_t
{
    SUCCESS,  /* Function has successfully converted the string to structure */
    NULL_PTR, /* Function is given NULL pointers to work with */
    INCORRECT /* Incorrect values for date or month or year */
} status_t;

status_t string_to_date_converter(char *input_string, my_date_t *result_date)
{
    if (input_string == NULL || result_date == NULL)
    {
        return NULL_PTR;
    }

    // Parsing day, month, and year using sscanf
    int day, month, year;
    if (sscanf(input_string, "%d/%d/%d", &day, &month, &year) != 3)
    {
        return INCORRECT;
    }
    // Checking if the date is valid or not
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0)
    {
        return INCORRECT;
    }

    // Assigning values to the result_date structure
    result_date->date = (uint8_t)day;
    result_date->month = (uint8_t)month;
    result_date->year = (uint16_t)year;

    return SUCCESS;
}

int main()
{
    // Example usage
    char date_string[] = "06/06/2023";
    my_date_t output;

    status_t is_good = string_to_date_converter(date_string, &output);

    if (is_good == SUCCESS)
    {
        printf("Conversion successful\n");
        printf("Date: %d\n", output.date);
        printf("Month: %d\n", output.month);
        printf("Year: %d\n", output.year);
    }
    else if (is_good == NULL_PTR)
    {
        printf("Error: NULL pointers\n");
    }
    else if (is_good == INCORRECT)
    {
        printf("Error: Incorrect date format\n");
    }

    return 0;
}