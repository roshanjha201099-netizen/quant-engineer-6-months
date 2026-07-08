def add_two_num(a:int,b:int)->int:
    if not isinstance(a,int) or not isinstance(b,int):
        raise ValueError("Both inputs must be integers.")
    return a+b

def substract_two_num(a:int,b:int)->int:
    if not isinstance(a,int) or not isinstance(b,int):
        raise ValueError("Both inputs must be integers.")
    return a-b

def multiply_two_num(a:int,b:int)->int:
    if not isinstance(a,int) or not isinstance(b,int):
        raise ValueError("Both inputs must be integers.")
    return a*b


if __name__=="__main__":
    num1=555
    num2=666
    result=add_two_num(num1,num2)
    result_sub=substract_two_num(10,2)
    result_mul=multiply_two_num(10,2)
    print(f"The sum of {num1} and {num2} is: {result}")
    print(f"The substarction of {10} and {2} is: {result_sub}")
    print(f"The multiplication of {10} and {2} is: {result_mul}")