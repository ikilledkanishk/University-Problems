'''A. Given a list of numbers (integers), find second maximum and second minimum in this list.
Input: 10 11 100 200 300 34
Output: 200 11'''

#Source Code:
def find_second_extremes(numbers):
    unique_nums = list(set(numbers))
    if len(unique_nums) < 2:
        return "List needs at least two unique numbers"  
    unique_nums.sort()
    second_min = unique_nums[1]
    second_max = unique_nums[-2]
    return second_max, second_min

'''B. Given a list L write a program to make a new list and match the numbers inside list L to its respective
index in the new list. Put 0 at remaining indexes. Also print the elements of the new list in the single
line.
Input: [1,5,2]
Output: [0, 1, 2, 0, 0, 5]'''
#Source Code:
def index_match(L):
    if not L:
        return [] 
    max_val = max(L)
    new_list = [0] * (max_val + 1) 
    for num in L:
        if num >= 0:
            new_list[num] = num          
    return new_list
L = [1, 5, 2]
output_list = index_match(L)
print(output_list)

'''C. Take two statements from user as input and show
a. Unique common words
b. All unique words
c. All unique words present in 1
st statement but not in second
Input: Here is Python
We are learning
Python Output: a. {'Python'}
b. {'We', 'are', 'learning', 'is', 'Python', 'Here'}
c. {'is', 'Here'}'''
#Source Code:
def analyze_statements(stat1, stat2):
    set1 = set(stat1.split())
    set2 = set(stat2.split())
    common = set1.intersection(set2)
    all_unique = set1.union(set2)
    only_in_first = set1.difference(set2)
    print(f"a. {common}")
    print(f"b. {all_unique}")
    print(f"c. {only_in_first}")
# Example usage
statement1 = "Here is Python"
statement2 = "We are learning Python"
analyze_statements(statement1, statement2)

'''D. Take a string as input. Form a dictionary which will have each unique word present in the string as key
and frequency of the word as value.
Input: Python is inspired by Monty Python
Output: {“Python”: 2, “is”: 1, “inspired”: 1, “by”: 1, “Monty”: 1}'''
#Source Code:
def word_frequency(text):
    words = text.split()
    frequency_dict = {}
    for word in words:
        frequency_dict[word] = frequency_dict.get(word, 0) + 1
    return frequency_dict

# Example usage
input_str = "Python is inspired by Monty Python"
print(word_frequency(input_str))


'''E. Given a list of strings, write a program to write sort the list of strings based on last character of each
string.
Input: ['ram', 'shyam', 'lakshami']
Output: ['lakshami', 'ram', 'shyam']'''
#Source Code: 
def sort_by_last_char(strings):
    return sorted(strings, key=lambda x: x[-1])

# Example usage
input_strings = ['ram', 'shyam', 'lakshami']
print(sort_by_last_char(input_strings))
