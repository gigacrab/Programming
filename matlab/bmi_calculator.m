weight = input("Enter your weight in kg: ");
height = input("Enter your height in m: ");
bmi = weight/height^2;
if bmi > 0
    fprintf("Your BMI is %.2f. ", bmi)
    if bmi < 18.5
        fprintf("You are underweight.\n");
    elseif bmi < 24.9
        fprintf("You are healthy.\n");
    elseif bmi < 29.9
        fprintf("You are overweight.\n")
    else
        fprintf("You are obese.\n")
    end
else
    fprintf("Invalid input.\n");
end