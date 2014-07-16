#import"Student.h"
#import<stdio.h>

@implementation Student
+(void) print {
    printf("name:%s   age:%d  ");
}
-(void) setName:(char *) _name {
}
-(void) setAge:(int ) _age {
    age = _age;
}
@end