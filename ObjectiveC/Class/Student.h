@interface Student{
	char * name;
	int age;
}

+(void) print;
-(void) setName	:(char *)	_name;
-(void) setAge	:(int)		_age;
@end