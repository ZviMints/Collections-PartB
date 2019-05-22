<img src="https://media.licdn.com/dms/image/C4D0BAQGD7npMPoXymw/company-logo_200_200/0?e=2159024400&v=beta&t=TZ8Ub3U2jCZgA1_kAx6SE8jmAcSJkbiZAuN6Kn1_lW0" height="100px">

Collections Project made during CPP course at Ariel University 2019. <br>
<b>Made by:</b> Zvi Mints and Or Abuhazira and Eilon Tsadok. <br>

## Purpose: 
In this project we perform a combination of different iterations such as:
1. <b>range(a,b)</b> - get 2 numbers and print all the numbers in [a,b), for example for input range(1,4) the output will be 1,2,3.
2. <b>chain(a,b)</b> - combines 2 classes, which can be different, so the transition in the iterator to the collection is continuous on all elements, for example for input chain(range('a','e'), string("hello"))) the output will be abcdhello.
3. <b>zip(a,b)</b> - combines the i'th element from a and the i'th element of b to a pair, for an input zip(range(1,6), string("hello") the output will be 1,h  2,e  3,l  4,l  5,o.
4. <b>product(a,b)</b> - combines each i from the first object and each j from the b'th object. for example for input product(range(1,4), string("hello") the output will be 1,h  1,e  1,l  1,l  1,o  2,h  2,e  2,l  2,l  2,o  3,h  3,e  3,l  3,l  3,o.
5. <b>powerset(a)</b> - returns all the powerset of the object a, for example for input powerset(range(1,4)) the output will be {}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}

After implementing the actuators, you can use a <b>for-each loop</b>.
