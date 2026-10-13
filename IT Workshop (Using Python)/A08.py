'''A. A string with parentheses is well formed if all parentheses are matched: every opening bracket has a
matching closing bracket and vice versa. Write a Python program to an expression and call a function
wellBrackated() which will return True if the input is well bracketed else False. Handle all the
exception where required.'''
#Source Code:

def wellBrackated(expr):
    try:
        if not isinstance(expr, str):
            raise TypeError("Input must be a string")
        stack = []
        mapping = {")": "(", "}": "{", "]": "["}
        for char in expr:
            if char in mapping.values():
                stack.append(char)
            elif char in mapping:
                if not stack or stack[-1] != mapping[char]:
                    return False
                stack.pop()
        return len(stack) == 0
    except Exception:
        return False
