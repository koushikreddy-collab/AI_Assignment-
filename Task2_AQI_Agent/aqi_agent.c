#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    int pm25, pm10, no2;
    int aqi;
    char category[20];

    file = fopen("sensor_data.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(file, "%d %d %d", &pm25, &pm10, &no2);
    fclose(file);

    aqi = pm25;

    if (pm10 > aqi)
        aqi = pm10;

    if (no2 > aqi)
        aqi = no2;

    if (aqi <= 50)
        sprintf(category, "Good");
    else if (aqi <= 100)
        sprintf(category, "Moderate");
    else if (aqi <= 200)
        sprintf(category, "Poor");
    else if (aqi <= 300)
        sprintf(category, "Very Poor");
    else
        sprintf(category, "Severe");

    printf("PM2.5 = %d\n", pm25);
    printf("PM10  = %d\n", pm10);
    printf("NO2   = %d\n", no2);
    printf("AQI   = %d\n", aqi);
    printf("Category = %s\n", category);

    return 0;
}
