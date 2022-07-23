# Chapter 1|Arrays and Strings from Cracking the Coding Interview

> #### The main content of this chapter is as follows:
>
> - **Hash Tables.**
> - ArrayList & Resizable Arrays.
> - StringBuilder.
> - interview Questions.

- ### Hash Tables

  1. ***```Definition```***: A Hash table is a data structure that maps keys to values for highly efficient lookup.
  2. ***```Implementation```***: use an array of linked lists and a hash code function.
     - there is a two method almost to Implement a Hash table:
       - Chaining
       - Open Addressing
###### ```Note: we use those methods to avoid the Collision!```      
#### Chaining


- To insert a key and value, we do the following:

> 1.  Compute the key's hash code (usually be an int or long).
>
>     - Note that two different keys could have the same hash code.
>
>     - As there may be an infinite number of keys and a finite number of ints.
>
> 2.  map the hash code to an index in the array
>
>     - This could be done with someting like **_` hash(key) % Array_length`_**.

>     -  Tow different hash codes could map to the same index.
>
> 3.  At this index, there is a linked list of keys and values.
>
>     - Store the key and value in this index.

> ***eg. page 88:***
>
> "hi" after hashing 𐃘 **10320** mapped to 𐃘 0
>
> "abc" after hashing 𐃘 **980** mapped to 𐃘 0
>
> "aa" after hashing 𐃘 **897** mapped to 𐃘 2
>
> "qs" after hashing 𐃘 **897** mapped to 𐃘 2
>
> "pl" after hashing 𐃘 **63** mapped to 𐃘 3
>
- So the linked list will be as follow:
>
> 
> |0| 𐃘 "hi" 𐃘 "abc"
>
> |1|
>
> |2| 𐃘 "aa" 𐃘 "qs"
>
> |3| 𐃘 "bl"
>
> |4|


#### Open Addressing

- will be added later on.


#### references
1. [Gayle Laakmann McDowell](https://www.youtube.com/watch?v=shs0KM3wKv8).
1. [Mostafa Saad](https://www.youtube.com/watch?v=Rp3KxUdV09Y).
3. [topcoder](https://www.topcoder.com/thrive/articles/getting-started-with-hash-table-data-structure-introduction).