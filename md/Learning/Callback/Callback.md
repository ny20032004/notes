Callback
--------

#### What is _callback_
"A _Callback_ is a piece of executable code that is passwd as an argument to other code, which is expected to call back(execute) the argument at some convenient time."  -- wikipedia

Different programming languages have different implement of callback, but they are often implemented with subroutines, lambda expression, blocks, or function pointer.


There are two kinds of callbacks:

  1. Blocking callbacks(also synchronous callbacks): 
    * Blocking callbacks are invoked before a function returns.
    * Blocking callbacks often, but not always, reply on a single thread, so blocking callbacks use less for synchronization or delegating work to another thread.
  1. Deferred callbacks(also asynchronous callbacks):
    * Deferred callbacks are invoked after a function returns.
    * Deferred callbacks are often used in the context of I/O operations or event handling.
    * Deferred callbacks imply the existence of multiple threds.

#### Some implements tips
  First of all, we should know that to implement a callback, we should let a function to be a argument passed to another function, and being invoked.

  Here is some implements:

  1. Using function pointer:
    * C/C++ and Pascal allow function pointer to be a argument. Example of C

            void executer(int input, int (*func_ptr)(int)){
                (*func_ptr)(input);
            }
            int add_one(int input){
                printf("%d\n", input + 1);
            }
            int add_two(int input){
                printf("%d\n", input + 2);
            }
            int main(){
                executer(2, add_one);
                executer(2, add_two);
                return 0;
            }

  1. Language-support function argument
    * Suching as Python, JavaScript, Perl and Php, language support a function to be a argument passed to another function. An example of Python:

            def executer(input, func):
                return func(input)

            def add_one(input):
                print(input + 1)

            def add_two(input):
                 print(input + 2)

            if __name__ == "__main__":
                 executer(1, add_one)
                 executer(1,add_two)

  1. CLI Languages use a delegate to implement callback.
  1. Functional languages supporting a function passed to other functions as a callback.(See the Python example above). By the way, functional language also allow you to pass a function to other function as data, or return from the functions.
  1. Pure Object-oriented programming language like Java implement callback by passing an instance of an abstract class or interface. Then the receiver call the methods of the class or interface. This looks like the _observer pattern_


#### Some example from network

1. JavaScript can pass a function as argument.:

        <script type="text/javascript">
            function someAction(x, y, someCallback) {
                return someCallback(x, y);
            }

            function calcProduct(x, y) {
                return x * y;
            }

            function calcSum(x, y) {
                return x + y;
            }

            // alerts 75, the product of 5 and 15
            alert(someAction(5, 15, calcProduct));
            // alerts 20, the sum of 5 and 15
            alert(someAction(5, 15, calcSum));
        </script>

1. C language

        /*
        * This is a simple C program to demonstrate the usage of callbacks
        * The callback function is in the same file as the calling code.
        * The callback function can later be put into external library like
        * e.g. a shared object to increase flexibility.
        *
        */

        #include <stdio.h>
        #include <string.h>
        #include <stdlib.h>

        typedef struct _MyMsg {
                int appId;
                char msgbody[32];
        } MyMsg;

        void myfunc(MyMsg *msg)
        {
                if (strlen(msg->msgbody) > 0 )
                        printf("App Id = %d \n Msg = %s \n", msg->appId, msg->msgbody);
                else
                        printf("App Id = %d \n Msg = No Msg\n",msg->appId);
        }

        /*
         * Prototype declaration
         */
        void (*callback)(void *);

        int main(void)
        {
            MyMsg msg1;
            msg1.appId = 100;
            strcpy(msg1.msgbody, "This is a test\n");

            /*
             * Assign the address of the function 'myfunc' to the function
             * pointer 'callback'
             */
            callback = (void *)myfunc;

            /*
             * Call the function
             */
            callback((MyMsg*)&msg1);
         
            return 0;
        }