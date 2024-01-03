# Sequential Containers
    A container holds a collection of objects of a similar type. The sequencial containers lets the programmer control the order in which the elements are stored and accessed, but order does't depend on the values instead it corresponds to the
    position at which the elements are put in to the container.       
        vector - flexing size array
                 supports fast random access, subscripts can be used
                 insertion or deletion other than the back will be slow
        deque  - double ended queue
                 supports fast random access,
                 fast insertion and deletion at the front and back
        list   - doubly linked list
                 fast insertion and deletion at anywhere in the container
                 no random access, only bidirectional access,  iterates through the elements
        forward_list - singly linked list
                 sequencial access in one direction
                 fast insertion and deletion at any point
        array  - fixed sized array
                 supports random access
                 cannot add or remove items
        string - vector like container that stores only characters
                 fast insertion and deletion at the back
                 fast random access
    Any container can hold any type including another container as its elements, But container operations imposes their own
    restrictions for what types they can be use
        ex :- a type with no constructor
              vector<noDefault> vec1(10, init)  // ok : init is used to construct the elements
              vector<noDefault> vec2(10)        // error : as noDefault as no default constructor, vec2 won't be able to     
                                                           constructs objects

![ContainerOperations](../../pictures/ContainerOperations1.png)     
![Container Operations](../../pictures/ContainerOperations2.png)     
![Defining and Initialising Containers](../../pictures/Defining_and_initialisers_containers.png)     
![Alt text](../../pictures/ContainerOperations9.2.1.png)
![Alt text](../../pictures/ContainerOperations9.2.2.png) 
![Alt text](../../pictures/Defining_and_initialisers9.3.png) 
![Alt text](../../pictures/InitialisingContainers9.3.png) 
![Alt text](../../pictures/ContainerAssignmentOperations9.4.png) 
![Alt text](../../pictures/additionToSequentialContainers9.5.png) 
![Alt text](../../pictures/AddingElementsToSequentialContainers9.5.1.png) 
![Alt text](../../pictures/AddingElementsToSequentialContainers9.5.2.png) 
![Alt text](../../pictures/invalidatingIterators.png) 
![Alt text](../../pictures/accessingSequentialContainers9.6.png) 
![Alt text](../../pictures/AccessOperationsToSequentialContainers9.6.png) 
![Alt text](../../pictures/eraseSequentialContainers9.7.png) 
![Alt text](../../pictures/ErasingOperationsOnSequentialContainers9.7.png)
![Alt text](../../pictures/forwarlistModification9.8.png) 
![Alt text](../../pictures/containerSizeManagements9.9.png) 
![Alt text](../../pictures/SequentialContainersSizeOperations9.9.png)
![Alt text](../../pictures/containerSizeManagement9.10.png) 
![Alt text](../../pictures/stringConstruction9.11.png) 
![Alt text](../../pictures/substringOperations9.12.png) 
![Alt text](../../pictures/stringModifications9.13.png) 
![Alt text](../../pictures/stringModifications2.png) 
![Alt text](../../pictures/st9.13.png) 
![Alt text](../../pictures/stringSearch9.14.png) 
![Alt text](../../pictures/stringCompare9.15.png) 
![Alt text](../../pictures/stringAndNumbersConversions9.16.png) 
![Alt text](../../pictures/adaptersContainers9.17.png) 
![Alt text](../../pictures/stackOperations9.18.png) 
![Alt text](../../pictures/queueOperations9.19.png) 
![Alt text](../../pictures/IteratorInvalidators.png) 






 


            