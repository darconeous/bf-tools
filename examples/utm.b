#!/usr/bin/bf
[A universal Turing machine from Yurii Rogozhin's article "Small universal Turing machines", in Theoretical Computer Science, 168(2):215-240, 20 November 1996. Thus, a very direct proof that brainfuck is Turing-complete. For i/o formats and so on, read below; for fuller detail, dig up the article.

If you just want a quick and complete test case, the input b1b1bbb1c1c11111d should produce the output 1c11111.

-Daniel B. Cristofani (cristofd@hevanet.com).

This Turing machine achieves Turing-completeness not by simulating other Turing machines directly, but by simulating a Turing-complete class of tag-systems. A tag-system transforms strings over an alphabet A = {a[1],a[2],...,a[n], a[n+1]} as follows: a positive integer m is chosen, and so is a function P that maps each a[i] for 1<=i<=n to a string P(a[i]) over the alphabet A. Now:

1. if the string being transformed has fewer than m elements, the whole process stops now.
2. m elements are removed from the beginning of the string
3. call the first element removed a[k]; if k=n+1 the whole process stops now.
4. P(a[k]) is appended to the string.
5. steps 1-5 are repeated.

The particular class of tag-systems this Turing machine simulates is the class where m = 2, the initial string has length at least 2, and all P(a[i]) where 1<=i<=n are of the form a[n]a[n]B[i] where B[i] is some string over the alphabet A (B[i] is the empty string if and only if i=n).

The input for this program is mildly complex, and there is no error checking.

-The representation of a symbol a[i] from the alphabet A is a string of 1s which is one element longer than twice the combined length of all P(a[j]) where 1<=j<i.

-a value like P(a[i]) = a[n]a[n]a[w]a[x]...a[y]a[z] is represented as follows:
b 1
b 111...(as many as required to represent a[z] as described above) b
b 111...(to represent a[y] as described above) b
.
.
.
b 111...(to represent a[x]) b
b 111...(to represent a[w]) b
b 111...(to represent a[n]) b
b 111...(as many as for a[n] as described above, MINUS the number of 1s that represent a[i]; and no final b)

-The function P is represented by listing all its outputs in the order P(a[n]), P(a[n-1]),...,P(a[2]),P(a[1]). The representation of P(a[n+1])=STOP is done for you.

-The initial string a[q]a[r]...a[s]a[t] to be transformed by the tag-system is represented as
111...(as many as required to represent a[q] as above) c
111...(to represent a[r]) c
.
.
.
111...(to represent a[s]) c
111...(to represent a[t]; note that there is no final c.)

-The input to this program is a function P as described above, then a single b, then the initial string to be transformed. Run all the 1s, bs, and cs together in one line with nothing between, followed by a linefeed, or a period if a linefeed is problematic for your implementation.

-The output format, if the program terminates, is the same as the input format for the initial string, and represents the final state of the transformed string, with a final a[n+1] appended due to a peculiarity of the Turing machine's algorithm.

-An example.
A tag-system over the alphabet A = {a[1], a[2], a[3], a[4]}, where m = 2 and:
P(a[1]) = a[3]a[3]a[2]a[1]a[4]
P(a[2]) = a[3]a[3]a[1]
P(a[3]) = a[3]a[3]
P(a[4]) = STOP

meets the criteria above; and when applied to the initial string a[2]a[1]a[1] it gives:
a[2]a[1]a[1]
        a[1]a[3]a[3]a[1]
                a[3]a[1]a[3]a[3]a[2]a[1]a[4]
                        a[3]a[3]a[2]a[1]a[4]a[3]a[3]
                                a[2]a[1]a[4]a[3]a[3]a[3]a[3]
                                        a[4]a[3]a[3]a[3]a[3]a[3]a[3]a[1]
                                                a[3]a[3]a[3]a[3]a[3]a[1]
and then it's done.

Now, the encoding:

a[1] is 1
a[2] is 11111111111
a[3] is 11111111111111111
a[4] is 111111111111111111111

P(a[1]) is b1 b111111111111111111111b b1b b11111111111b b11111111111111111b b1111111111111111
P(a[2]) is b1 b1b b11111111111111111b b111111
P(a[3]) is b1 b11111111111111111b b

the initial string is 11111111111c1c1

and so the whole input is

b1 b11111111111111111b b
b1 b1b b11111111111111111b b111111
b1 b111111111111111111111b b1b b11111111111b b11111111111111111b b1111111111111111
b
11111111111c1c1

which when run together for input to the program becomes

b1b11111111111111111bbb1b1bb11111111111111111bb111111b1b111111111111111111111bb1bb11111111111bb11111111111111111bb1111111111111111b11111111111c1c1

For those interested, the state table of the machine is
11<L1    210R2    311R3    410R4
1b>R1    2b>L3    3b<R4    4bcL2
1>bL1    2><R2    3>bR3    4><R4
1<0R1    2<>L2    3< H     4<   
10<L1    201L2    30cR1    40cL2
1c0R4    2cbR2    3c1R1    4cbR4
where the initial state is 1, tape cells are set as per the input but with the termination code P(a[n+1])=STOP represented as a <b at the left end and all other cells on both sides (actually, only the right is needed) holding symbol 0, and the head is initially at the first 1 in the code for the initial string.

The minimal test case b1b1bbb1c1c11111 represents the tag-system where P(a[1]) = a[1]a[1] and P(a[2]) = STOP, applied to the string a[1]a[1]a[2]. This runs for 518 steps of the Turing machine, exercising all 23 Turing machine instructions, before halting with the output string a[1].
]


+++>+
[>>,[>+++++<[[->]<<]<[>]>]>-[<<<->++++++>>-[<<[-]>++>[<<+>->-]]]
<[-<[<]++[>]]<]<-[[>>>+<<<-]<]++>>>+[-[>++++++<-]>[<+>-]
+<<<+++>+>
  [-
    [<<+>->-
      [<<[-]>>-
        [<<++>+>-
          [<<-->->>+++<-
            [<<+>+>>--<-
              [<<->->-
                [<<++++>+>>+<-
                  [>-<-
                    [<<->->-
                      [<<->>-
                        [<<+++>>>-<-
                          [<<---->>>++<-
                            [<<++>>>+<-
                              [>[-]<-
                                [<<->>>+++<-
                                  [<<->>>--<-
                                    [<<++++>+>>+<-
                                      [<<[-]>->>++<-
                                        [<<+++++>+>>--<-
                                          [<->>++<
                                            [<<->>-
]]]]]]]]]]]]]]]]]]]]]]<[->>[<<+>>-]<<<[>>>+<<<-]<[>>>+<<<-]]>>]
>[>+++++>[<->-]<]>>[+++[<+++++>--]<[<+>>+++++<-]>-.[-]>]<<<.
