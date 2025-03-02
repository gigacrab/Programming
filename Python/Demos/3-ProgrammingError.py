'''
Question 1
a) if statement compares a string and an integer, it will always return false
b) 
    Solution 1: 
    CODE = 5
    Solution 2:
    if code == int(CODE):
'''

'''
Question 2
a) to combine string for the input argument, you can only use the string concatenation and not a comma
b) input(name.title() + ' enter your age:')
'''

'''
Question 3
a) cannot compare string with an integer, both must either be string or number for comparison, due to the inequality comparison, this will return a TypeError
b) 
    Solution 1
    age=int(input('Enter your age: '))
    Solution 2
    if int(age) >= 18 or int(age) <= 120:
'''

'''
Question 4
a) because of the or logical operator, as long as one condition is met, the expression will return true, covering all real numbers
b) 
    Solution 1
    if age < 18 or age > 120:
    Solution 2
    if not age >= 18 or not age <= 120:
'''