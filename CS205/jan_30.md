Date: 2013-01-30  
Title: Jan 30 Notes
Published: true  
Type: post  
Excerpt: Notes on Section 1.1

# Jan 30
Some examples on page 4 -
## Section 1.1 - Logic

-   Logic started as a model for **reasoning**.
-   Logic viewed as a **foundation** of mathematics.
-   Used as a method of **precise specification**.

### In computer science

-	A language based entirely of logic, called **prolog**.
-	There are two kinds of logic
1. Propositional Logic
2. Predicate Logic

#### Propositional Lgoic
-	1 + 1 = 2
-	2 +3 = 5
	
##### Non propsitional logic
-	Questions, obscure statements, paradoxes

Paradox Example: 	
> This statement is wrong

###### Ground Propostions
- P&Q = P /\ Q	the /\ is an "AND"
- P || Q = P V Q the V is an "OR" 
- P ⊕ Q = Exclusive Or
	-	The exclusive or means one or the other only
- P → Q = Implies.
	-	The first argument is the **proposition** and the second argument is the **consequence**.
- P ⇔ Q = If and Only If
- Use truth table, see page 4
- How many connectors could there be? 
	-	A counting principle
	-	Let there be 3 boxes, with V values (IE: 4 values)
	-	The answer would be $$4^3$$
	-	With a formula of $$v^b$$
	-	For example, with 2 arguments and 4 connectors, there is 2^4 or 16 total

Implies example:
> If you study well you will get an A

Examples for implies wording

	*	If P then Q
	*	Q if P
	*	P is sufficient for Q
	*	Q whenever P

###### Compound Propositions
-	Look similar to (2+3)*5

Example:
> (P&Q)||R

-	See page 4

###### Translating English to Logic
>	If I go home or I go to my office I will not go shopping

-	Must translate and underline important words.
-	For example:

>	**If** *I go home* **or** *I go to my office* *I will **not** go shopping*

-	I go home becomes s1
-	I go to my office is s2
-	I will not go is s3
-	So, we get (s1 || s2) → !s3, and a truth-table is used to evaluate it
-	What if two statements are equivalent?
-	F1 and F2, F1 is equivalent to F2 and is denoted by F1 ≡ F2 (triple line equals). 
-	**Equivalence** - F1 and F2 have the same truth table

-	**Tautology** - something which is always true

Tautology Example
>	p || !p

Contradiction Example
>	p & !p


##### DeMorgan's
-	One of most famous examples, makes sense by a truth table.[^1]
[^1]: Notebook page 5
