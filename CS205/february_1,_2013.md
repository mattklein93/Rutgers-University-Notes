# February 1, 2013
-- -
## Recap
### Prepositions and Formulas of Prepositions (Compound Prepositions)
-	Formula example, (P||Q)&R
-	There 16 binary connectors (4 or 5 are mostly used)and 1 unary connector

#### Precedence Order

Number|	Name				|	Symbol
------|--------------------|----------
1.	  |	Not					|	$${\lnot}$$
2.	  |	Or					|	$${\lor}$$
3.	  |And					|	$${\land}$$
4 	  |	Implied				|	$${\to}$$
5 	  |	Double implication	|	$${\leftrightarrow}$$

-	**Tautology** - always true
-	**Contradiction** - always false
-- -
### Equivalence
-	Two formulas, F1 ≡ F2 if their truth values are equivalent
##### De Morgan's Rule
1.	$${\lnot(P \land Q) \equiv \lnot P \lor  \lnot Q}$$
2.	$${\lnot(P \lor Q) \equiv \lnot P \land \lnot Q}$$
3.	$${P \to Q \equiv \lnot P \lor Q}$$
> This is the same because if P is false, then !P is true, then Q could be either
> true or false, it does not matter. Only one or the other matters as it is an
> **OR** statement. If !P is false, Q could still be true.

### Identities of Equivalence
$$	{P \lor F \equiv P} $$
***
$$	P \lor T \equiv T $$
***
$$	P \land F \equiv F $$
***
$$	P \land T \equiv P $$
***
$$	P \lor Q \equiv Q \lor P $$
***
$$	P \land Q \equiv Q \land P $$
***
$$	P1 \land P2 \lor P3 … \lor PK $$
	-	Any order can be used because of distrubution
***
$$ P \land !P \equiv F $$
***
$$ P \land \lnot P \equiv T $$
***
$$ (P \to Q) \equiv \lnot Q \to \lnot P $$
***
$$((P \land Q) \to R) \equiv P \to(Q \to R) $$
###### Left Side
1. $$ \lnot (P \land Q)\lor R $$
2. $$ \lnot P \lor \lnot Q \lor R $$

###### Right Side
1. $$ P \to (\lnot Q \lor R) $$
2. $$ \lnot P \lor \lnot Q \lor R $$
***
$$ \lnot (P_1 \lor P_2) \equiv \lnot P_1 \land \lnot P_2 $$
Suppose we have 3
$$ \lnot (P_1 \lor P_2 \lor P_3) \equiv \lnot P_1 \land \lnot P_2 \land P_3 $$
What if we have any number?
$$ \lnot (P_1 \lor P_2 … \lor P_m) \equiv \lnot P_1 \land \lnot P_2 … \land P_m$$
***
### Functional Completeness 
-	**Functional Complete** - Set of operators is functionally complete if every formula can be expressable
$$\{\land,\lor,\lnot}$$
-	**Lemma** - every formula can be expressed as a *disjunction* of 	*conjunctions*
	-	This is called **disjunctive normal form** (DNF)
$$\{(P_1 \land \lnot P_2 \land P_3) \lor (\lnot P_1 \land P_3)\land (P_1 \land \lnot P_3) \land (…)}$$

$${F \equiv (Q_1 \lor Q_2) \to \lnot Q_3}$$

$${Q_1}$$	|	$${Q_2}$$	|	$${Q_3}$$	|	F	| Expression
----|------|--------|----
0	|	0	|	0	|	1	|	$${\lnot Q_1 \land \lnot Q_2 \land \lnot Q_3}$$
0	|	0	|	1	|	1	|	$${\lnot Q_1 \land \lnot Q_2 \land Q_3}$$
0	|	1	|	0	|	1	|	$${\lnot Q_1 \land Q_2 \land Q_3}$$
0	|	1	|	1	|	0	|	Nothing
1	|	0	|	0	|	1	|	$${Q_1 \land \lnot Q_2 \land \lnot Q3}$$
1	|	0	|	1	|	0	|	Nothing
1	|	1	|	0	|	1	|	$${Q_1 \land Q_2 \land \lnot Q_3}$$
1	|	1	|	1	|	0	|	Nothing

###### Compute DNF of $${P \to Q}$$

P	|	Q	|	$${P \to Q}$$ | Expression
----|-------|-----------------|------------
1	|	1	|	1				|	$${(P \land Q) \lor (\lnot P \land Q) \lor (\lnot P \lor \lnot Q)}$$
1	|	0	|	0				| Nothing
0	|	1	|	1				| Nothing
0	|	0	|	1				| Nothing