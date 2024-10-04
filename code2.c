#include <stdio.h>

float celsius_to_fahrenheit(float celsius){
    return ((9.0/5.0) * celsius) + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    float output = (5.0/9.0)*(fahrenheit - 32);
    return output;
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return (fahrenheit - 32) * (5.0/9.0) + 273.15;
}

float kelvin_to_fahrenheit(float kelvin){
    return (kelvin - 273.15) * (9.0/5.0) + 32;
}

void categorize_temp(float celsius){
    
    if(celsius <= 0){
        printf("Temperature Category: Freezing \n");
        printf("Find a fireplace");
    }else if(celsius <= 10){
        printf("Temperature Category: Cold \n");
        printf("Wear a jacket");
    }else if(celsius <= 25){
        printf("Temperature Category: Comfortable \n");
        printf("Its perfect out");
    }else if(celsius <= 35){
        printf("Temperature Category: Hot \n");
        printf("Dress lightly");
    }else{
        printf("Temperature Category: Extremly Hot \n");
        printf("Find some AC");
    }
}

int main()
{
    float temp_value, converted_temp;
    int current_scale, target_scale;
    int valid_input = 1;
    
    while(valid_input){
        printf("Enter a temperature: ");
        scanf("%f", &temp_value);
        printf("Choose a currnet scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
        scanf("%d", &current_scale);
        if(current_scale == 3 && temp_value < 0){
            printf("Kelvin cannot be negative, try again \n");
            continue;
        }
        printf("Choose a target scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
        scanf("%d", &target_scale);
        if(current_scale == target_scale){
            printf("Current scale and target scale cannot be the same, try again \n");
            continue;
        }
        valid_input = 0;
    }
    if(current_scale == 1){
        if(target_scale == 2){
            converted_temp = celsius_to_fahrenheit(temp_value);
        }else{
            converted_temp = celsius_to_kelvin(temp_value);
        }
    }else if(current_scale == 2){
        if (target_scale == 1){
            converted_temp = fahrenheit_to_celsius(temp_value);
        }else{
            converted_temp = fahrenheit_to_kelvin(temp_value);
        }
    }else{
        if(target_scale == 1){
            converted_temp = kelvin_to_celsius(temp_value);
        }else{
            converted_temp = kelvin_to_fahrenheit(temp_value);
        }
    }
    
    if(target_scale == 1){
        printf("Converted temperature: %f°C \n", converted_temp);
        categorize_temp(converted_temp);
    }else if(target_scale == 2){
        printf("Converted temperature: %f°F \n", converted_temp);
        converted_temp = fahrenheit_to_celsius(converted_temp);
        categorize_temp(converted_temp);
    }else{
        printf("Converted temperature: %fK \n", converted_temp);
        converted_temp = kelvin_to_celsius(converted_temp);
        categorize_temp(converted_temp);
    }
    
    
    
    
    
    
    
    
    
    

    return 0;
}
