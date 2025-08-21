# Proposal: Memory Objects
<!-- objects on ram (variables, pointers, addresses) -->

## Object Storage

### Stack

### Heap

## Variables

A *variable* is a temporal segment of memory that is allocated in the *program stack*.
A *value* is a sequence of bits that is located in a variable.

*Syntax:*
```
let [global|shared|local] [mut] variableName : variableType = value;
```
*Ebnf declaration:*
```ebnf
variable = "let", (|"global"|"shared"|"local"), (|"mut") ,identifier, ":", type, "=", value, ";" 
```

### Lifetime

A variable has 3 lifetime states:
- Declaration & Initilization: The variable is allocated in memory, and the memory region is filled with a value.

- Usage: The variable **CAN** be read or written in this state.

- Deallocation: When the scope of a variable reachs its end, the variable **MUST** be deallocated and be available for others variables.

### Cache Preference

- Global: The variables marked with *global* keyword **MAY** be allocated in system memory.
- Shared: The variables marked with *shared* keyword **MAY** be allocated in core-common cache.
- Local: The variables marked with *local* keyword **MAY** be allocated in core-exclusive caches.

Examples:
```
let global helloString = "hello";
let shared counter : u32 = 20;
let local niceValue : f64 = 0.333; 
```

>[!NOTE]
> The *cache preference* keywords suggest to the implementation where the variables be allocated *preferably*, but do not give guarantees about where the variable is allocated. 

### Visibility

### Mutability

If a variable is permitted to change its value after initilization, the variable is *mutable*.

A *mutable* variable **MUST** allow its value to be changed, otherwise, the variable is *inmmutable*.

In order to declare a variable as *mutable*, it **MUST** be specified using the *mut* keyword.
 
## References, Copies & Views

### References
A _reference_ a data type that store a reference to a value.

Also, the operator  ```=```  creates a reference from other reference or value.

If a _reference_ A is previouly created, and _reference_ B is created referencing A, both references **MUST** reference the same value.

### Copies
### Views

Examples:
```
let someValue : f64 = 0.4;
let someValueCopy = someValue;
let view someValueView = someValue;
let ref someValueRef = someValue;
```

## Memory Blocks