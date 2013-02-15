
#February 8, 2013
***
## Mechanics of Logic
-	$$\forall x (P(x)\land Q(x)) \equiv \forall x P(x) \land \forall Q(x)$$ is true because they produce the same truth table.
-	Is the following statement true?$$\forall x(P(x)\lor Q(X)) \equiv \forall x P(X) \lor \forall x Q(x)$$
	-	They are equivalent if they produce the *same* truth table.
	-	Show that when one side is true the other is, and vice-versa.
	-	$$P(X_1) = T$$ but Q can also be false at the same time $$Q(X_2) = F$$
	-	Left to right is *false* but going right to left is *true*
###### 	How do we find this out?
		>	Let P(x) mean that x is here. Let Q(x) mean that x is not here. The statement on the left says that "For all students, they are either here or not here." The statement on the right states that "For all students, they are here or for all students they are not here."
		
-	Is the following statement true? $$\lnot \forall x (P(x) \to Q(x)) \equiv \exists (P(x) \land \lnot Q(x))$$
###### Left Side
-	Use De Morgan's rule to manipulate the left side. $$\equiv \lnot \forall x (\lnot P(x) \lor Q(x))$$ Now remember how $$\lnot \forall x P(x) \equiv \exists x \lnot P(x)$$ is a true statement.
-	$$\equiv \exists x \lnot (\lnot P(x) \lor Q(x))$$
-	$$\equiv \exists x (P(x) \land \lnot Q(x))$$ Notice how the entire statement is equivalent, thus this statement is true.

### Logic Programming
-	A language called **Prolog**. Uses logic as a programming language.
***
### Section 1.4 - Nesting of Quantifies
-	For example [1], $$\forall x \exists y (x+y = 0)$$
-	$$\equiv \forall x P(x)\ where\ P(x) = \exists y(x+y=0)\ so\ our\ original\ is\ \forall x \exists y (x+y=0)$$

-	Example 2:
	-	S = the sum of two positive integers is positive. How do we solve this? Convert to logic (**phrasing**). $$\forall x \forall y((x>0\land y > 0) \to (x+y) > 0)$$
	-	Simplified as$$\forall x \forall y (x+y > 0)$$
-	Domain real numbers[^1], is this true? $$\forall y \exists x (x>y)$$ How is it true? Make this statement x as a function for y.
-	What about the following? $$\exists $$
[^1]: All numbers on the number line.