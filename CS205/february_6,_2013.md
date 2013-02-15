# February 6, 2013
***
## Review
$$\lnot , \land, \lor$$ is functionally complete, however we do not need all three.
$${\lnot, \land}$$ $${\lnot, \lor}$$ both are functionally complete because of De Morgan's law:
$${A \land B \equiv \lnot \lnot (A \land B) \equiv \lnot (\lnot A \lor \lnot B)}$$
$${\lnot(A \land B) \equiv \lnot A \lor \lnot B}$$
***
## Predicate Logic (Calculus)
-	For every real number **x**, (one of) the following is true: $$sin(x)^2 + cos(x)^2 = 1$$
$$5*x+3 = 15$$
-	Both are ambigious, what is X? So we must use predicate logic.
-	A **predicate** is a statement involving one or more variables in a *specified domain* (set) such that binding these variables to values in this domain turns this statement to a proposition.
>	A predicate is also called a **propositional function**.

-	For example, in $$5*x+3=15$$ if $$x-3 = -5$$ becomes true for all integers, but no positive 
-	Eventually, P(x) will be true can not be expressable through predicate logic.
***

### Unumerated Quantified
- Displayed as $$\forall\ X \in D,\ P(X)$$
- The truth value of $$\forall\ X \in D,\ x^2 \geq x$$ Let D be integers, is true. Decimals and do not work.

-	$$\forall\ X \in Real\ Numbers,\ 3x+5=15$$ $$\forall\ X \in Real,\ (sin(x)^2 + cos(x)^2 = 1)$$ These have a preposition because it is true or false.
-	Let D be empty. Let X be all the people on Earth who were born on the moon. $$\forall\ X \in D,\ (X\ speaks\ English)$$ It is defined to be true for D which is empty.


##### Non-math Example
-	Let D be all the students of Rutgers $$\forall\ S \in\ D\ (S\ is\ enrolled\ in\ 205)$$ This is *False*.

##### Alternate Displays
-	$$\forall\ X,\ P(X)$$
###### Finite only
- $$\forall\ X \in D,\ P(X) \equiv P(x_1)\land P(x_2)\land …P(x_…)$$ and $$D = {x_1,x_2,…,x_m}$$
***

### Existential
-	Displayed as $$\exists\ X \in\ D,\ P(X)$$ then there is an X. It is true if we can show at least one example. For example, Let D be empty, it is false because there is nothing to demonstrate with.
-	There is a relationship between $$\exists\ and \in$$ of $$\lnot\exists\ X \in D,\ P(X) \equiv \forall X \in D\ \lnot(P(X))$$
***

### Precedence Rules
-	$$\forall\ and\ \exists$$ have higher predence then **all** prepositonal operators
-	For example, $$\forall\ x\ P(x)\land Q(x)$$ $$\forall\ (P(x)\land Q(x))$$ has no truth value because we don't know x.
***

### Bound to and Scope
-	Consider the following $$\forall\ x (P(x)\land Q(x)) \lor Z(x)$$ x is bound to the set, but if we change $$\forall\ x (P(x)\land Q(y)) \lor Z(y)$$ then y is not bound, only x is.
***

### Exercises
1.	$$Let\ S\ be\ "all\ large\ cars\ get\ bad\ mileage".\ What\ is\ \lnot S$$
	-	$$S^1 = Some\ large\ cars\ have\ good\ mileage$$
	-	$$S^2 = All\ large\ cars\ have\ good\ mileage$$
		-	Both are correct. However, we must translate it logically. Steps:
		1.	Let G\(C\) be "C gets good mileage"
		2. Let L\(C\) be "C is large"
		3. $$S \equiv \forall C \in Cars(L\(C\)\to \lnot G\(C\))$$
			-	Negation $$\lnot S \equiv \lnot \forall C \in Cars(L\(C\)\to \lnot G\(C\))$$
			-	$$\exists C \lnot (L\(C\)\to \lnot G\(C\))$$
		4. $$S^1 \equiv \exists C \in Cars(L\(C\) \land G\(C\))$$
			-	Negation $$S^1 \equiv \exists C \in Cars(L\(C\) \land G\(C\))$$
			-	$$\exists C \lnot (\lnot L\(C\)\lor \lnot G\(C\))$$
		5. $$S^2 \equiv \forall C \in Cars(L\(C\) \to G\(M\))$$
			-	Negation $$S^2 \equiv \forall C \in Cars(L\(C\) \to G\(M\))$$
			-	$$\exists C (L\(C\)\land G\(C\))$$
2.	$$\lnot \forall P(x) \equiv \exists x \lnot P(x)$$
3.	$$\lnot \exists P(x) \equiv \forall x \lnot P(x)$$
4.	$$\forall x (P(x) \land Q(x)) \equiv \forall x P(x) \land \forall x Q(x)$$ is true because every possible x is true, the right side says the same thing just split up.
5.	$$\forall x (P(x) \lor Q(x)) \equiv \forall x P(x) \lor \forall x Q(x)$$ is true because of the same reasons. 
6.	$$\forall x (P(x) \lor Q(X)) \equiv \forall x P(x) \lor \forall x Q(X)$$
***
### Equivalence of Two Predicate Formulas
-	How do we express the equivalence of $$F_1 \equiv F_2$$ wait until February 7, 2013