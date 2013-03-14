# March 13, 2013 - Exam Review
***
## Logical Equivalences
### Identity Laws
-	$$$P \land T \equiv P$$$
-	$$$P \lor F \equiv P$$$

-	These will both be P because either of them depend on P, to be true or false. The first one, requires P to be true or false (thus it is P). The second requires P to be true or false (thus it is P).



### Domination Laws
-	$$$P \lor T \equiv T$$$
-	$$$P \land F \equiv F$$$

-	T or F will always occur, because regardless of what P is they will either be true or false. This occurs because anything $$$\lor T$$$ is true (or only requires one to be true), and anything $$$\land F$$$ is false (and requires only one to be false), think lazy boolean evaluation.

### Idempotent Laws
-	$$$P \lor P \equiv P$$$
-	$$$P \land P \equiv P$$$

-	These laws will be P because the entire statement can only be true or false.


### Double Negation Law
-	$$$\lnot(\lnot P)\equiv P$$$

-	Self-explanitory, a negation of a negation is the non-negated original.


### Communitive Laws
-	$$$P \lor Q \equiv Q \lor P$$$
-	$$$P \land Q \equiv Q \land P$$$

-	The ability to swap two truth values does not matter regarding the outcome.


### Assosciative Laws
-	$$$(P \lor Q) \lor R \equiv P \lor (Q \lor R)$$$
-	$$$(P \land Q) \land R \equiv P \land (Q \land R)$$$

-	The statement will stay the same because both conditionals will end up meaning the same, as only what is evaluated first changes.


### Distributive Laws
-	$$$P \lor (Q \land R) \equiv (P \lor Q) \land (P \lor R)$$$
-	$$$P \land (Q \lor R) \equiv (P \land Q) \lor (P \land R)$$$

-	Distrubtion of what is not in the parenthesis, only occurs if two operators are different.


### De Morgan's Laws
-	$$$\lnot (P \land Q) \equiv \lnot P \lor \lnot Q$$$
-	$$$\lnot (P \lor Q) \equiv \lnot P \land \lnot Q$$$

-	Inversion.


### Absorption Laws
-	$$$P \lor (P \land Q) \equiv P$$$
-	$$$P \land (P \lor Q) \equiv P$$$

-	Occurs with two different operators because the second conditonal becomes unimportant.


### Negation Laws
-	$$$P \lor \lnot P \equiv T$$$
-	$$$P \land \lnot P \equiv F$$$

-	Simply negation of a given conditional.
***
## Implication
-	Implication is only false if the second statement is false. The first statement is not important, a false statement means **anything** can happen.
-	Negating an implication provides an **and** statement.
-	Biconditionals, means both statements are true or both statements are false, (Both must be the same for truth.)