#import "MyClass.h"
#import <stdio.h>

@implementation MyClass
-(void) publicMethod {
    printf( "public method\n" );
}
@end

// private methods
@interface MyClass (Private)
-(void) privateMethod;
@end

@implementation MyClass (Private)
-(void) privateMethod {
    printf( "private method\n" );
}
@end
