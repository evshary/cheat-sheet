# Note that we should not use `__name__=="__main__"` while releasing packages
# This is convenience for debug
if __name__=="__main__":
    # import functions from other file in the same directory.
    import calculate
else:
    # if the module is by other application 
    from mypackage import calculate

def runAdd():
    print("This is Add function")
    print("result= 5+3="+str(calculate.add(5, 3)))
    return

def runMinus():
    print("This is Minus function")
    print("result: 5-3="+str(calculate.minus(5, 3)))
    return

# This will always run if we use myfunc.py
print("mymodule.py: Always run!")

# Only run if we run myfunc.py directly, not import
if __name__ == "__main__":
    print("mymodule.py: Only run if run mymodule.py directly.")
    runAdd()
    runMinus()
