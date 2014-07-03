

#list tuple dict set

#list
people = ["jackie", "hellen", "may"];

print people;

print len(people);

print people[0], people[1];

for p in people:
    print p;


people.pop();
print people;
people.append("May");
print people;

people.insert(1, "Tom");
print people;

people.pop(2);
print people;

people.append(123);
print people;

print "\n\n";

#tuple
weeky = ( "San", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat");
print weeky;

print weeky[2];

pi = (3.14159);
print pi;
pi = (3.14159,);
print pi;

#dict
cap = {
    "jiangsu": 'najing',
    'hubei': 'wuhan',
    'fujian': 'fuzhou'
};

print cap["jiangsu"];
print cap["fujian"];

print cap;

print 'hubei' in cap;
print 'sichuan' in cap;

for cp in cap:
    key = cp;
    print "%s => %s" % (key, cap[key]);


print cap.get("hunan");
print cap.get("hunan", "xxx");


#set
A = set([1,2,3]);
B = set([1,2,3,4,3,2,1]);
print A;
print B;
A.add(12);
B.add(20);
print A, B;
A.remove(12);
B.remove(20);
print A, B;
