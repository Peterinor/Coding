
#condition
# _age = raw_input("input your age:");

# age = int(_age);
age = input("input your age:");

print "Your age is :%d" % age;

if(age < 10):
    print "Hello boy";
elif(age < 30):
    print "Hello teens";
elif(age < 50):
    print "Hello Uncle";
else:
    print "Hello grand";


#loop
print '---for'
weeky = ( "San", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat");
for day in weeky:
    print day;

print '---while'
i = 0;
while i < len(weeky):
    print weeky[i];
    i = i + 1;



