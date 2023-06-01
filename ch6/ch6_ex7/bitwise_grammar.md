# The grammar

**Disjunction:**

`````` 
Exclusion
Disjunction '|' Exclusion
``````

**Exclusion:**

```````
Conjunction
Exclusion '^' Conjunction
```````

**Conjunction:**

``````
Inversion
Conjunction '&' Inversion
``````

**Inversion:**

``````
Bit
'!' Bit
'~' Bit
``````

**Bit:**

`````` 
0
1
Bit Bit
``````

