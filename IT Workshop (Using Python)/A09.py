'''A. Create a class A. Define the constructor which will show “Class A object created”. Define a method
show (), which will show “Showing Class A”. Define a destructor which will delete the object and
show “Object deleted!!!”.'''
#Source Code:

class A:
    def __init__(self):
        print("Class A object created")

    def show(self):
        print("Showing Class A")

    def __del__(self):
        print("Object deleted!!!")


'''B. Create a class B. Define the constructor with one argument (integer type) which will show “Class B
object created”. Define a method show (), which will show “Showing Class B object having value
val1”.'''
#Source Code:

class B:
    def __init__(self, val1):
        self.val1 = val1
        print("Class B object created")

    def show(self):
        print(f"Showing Class B object having value {self.val1}")
      

'''C. Create a class C inheriting class B. Define the constructor which will take two arguments (integer type)
which will initialize a class B object with 1
st argument and show “Class C object created”. Define a
method show (), which will show “Showing Class C with val1, val2.”.'''
#Source Code:

class C(B):
    def __init__(self, val1, val2):
        super().__init__(val1)
        self.val2 = val2
        print("Class C object created")

    def show(self):
        print(f"Showing Class C with {self.val1}, {self.val2}")
      

'''D. Create a class E by inheriting class A and B. Define the constructor so that if no argument is passed
while creating an object it will display “Class E object created”, if one (1) argument are passed it will
display “Class E object created with one value”. Also define a method show (), which will show
“Showing Class E” or “Showing Class E with value 1 and value 2” if no or one argument is passed to
it.'''
#Source Code:

class E(A, B):
    def __init__(self, val1=None):
        A.__init__(self)
        if val1 is None:
            B.__init__(self, 0)
            self.val1 = None
            print("Class E object created")
        else:
            B.__init__(self, val1)
            print("Class E object created with one value")

    def show(self, val2=None):
        if self.val1 is None:
            print("Showing Class E")
        else:
            print(f"Showing Class E with value {self.val1} and value {val2}")
          

'''E. “+” operator concat two Create a class F. Define a constructor which will take one string. Consider x
and y are two objects of class F, then if we perform x – y then it will give the characters (in order)
present in x but not in y.'''
#Source Code:

class F:
    def __init__(self, string_val):
        self.string_val = string_val

    def __sub__(self, other):
        result = []
        for char in self.string_val:
            if char not in other.string_val:
                result.append(char)
        return "".join(result)
      
