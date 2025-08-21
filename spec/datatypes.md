# Data Types

A _Data type_ is a representation of a memory block.
Each *data type* has a size, each size **MUST** be defined at compile-time.

The size of each data type **IS** calculated via the following formula:

```
    size = (size of all native data types fields) + (size of all compound data types fields)
```

Properties' size (whether at runtime or compile time) **MUST NOT** be included as part of the data type size.

To access to the size of a data type, call:

```
    sizeof(datatype)
```

Also, data types are layouts of _variables_ (defined at [Memory Objects](staging/memory_objects.md)),
to access to the size of a data type of a variable, call:


```
    sizeof(variable)
```

>[!NOTE]
> _sizeof(variable)_ returns size of the data type of a variable at **compile time**, so, if the variable has any allocations,
> _sizeof_ **SHOULD NOT** return the size at runtime.

Implementations **MUST** use the assigned sizes of each data type.

## Enumerations:

An *enumeration* data type is a collection of _enumerals_, the values
of each *enumeral* **MUST** be known at compile time.

*Syntax:*

```ebnf
    enumeration = "enum", identifier, ( | (":", type )) "{", { enumeral },"}", ";" ;
    enumeral = identifier, ":", (type|constantValue) ;
```


## Native Data Types

A _native_ data type is **NOT** compound by other data types.
A _native_ data type **MUST** be supported by all implementations.

### Boolean

A *boolean* data type is a data type that has **ONLY** two possible values,

```C
true
false
```

Implementations **MUST** ensure that boolean data type use these values only.

### Numerics

A *numeric* data type is a native data type that represents a number at the machine level.
Also, *floating point numeric* data types **MUST** use the IEEE 754 standard.

| Bitsize  | signed integer | unsigned integer | float |
|-|-|-|-|
| 16   |  i16  | u16  | f16  |
| 32   |  i32  | u32  | f32  |
| 64   |  i64  | u64  | f64  |
| 128  |  i128 | u128 | f128 |

>[!IMPORTANT]
> _unsigned float_ **IS NOT** part of the specification due to _float_ data type follows the IEEE 754 standard.

### Character

## Custom Data Types

The _custom data types_ (also referred as "compound data type") define a *composite* data type that occupy an amount of memory.

**syntax:**

```ebnf
type = "type", identifier, "{", { field | property }, "}"
```

Example:

```
type light {
    f32 posX;
    f32 posY;
    f32 posZ;
    f64 intensity;
};
```
