# GET_NEXT_LINE

read from fd, and return each line per gnl() runs.

```mermaid
flowchart TD;
  subgraph gnl;
    subgraph s0[check arguments error];
      c0[check fd, BUFFERSIZE] --> c1{is fd valid ?};
      c1 -- Yes --> c2{is BUFFERSIZE greater than zero ?};
      c1 -- No --> c3[return NULL];
      c2 -- No --> c3;
    end s0;
    c2 --Yes--> s1{is stored buffer exist ?};
    subgraph s2[search new line];
      a0{is new line in strings ?} --Yes--> a1[get pointer to new line];
    end s2;
    subgraph s3[read buffer];
      b0["read from buffer"] --> b1{"is return val greater than 0 ?"};
      b1 --No--> b2["save read strings to stored buffer"];
      b2 --> b0;
    end s3;
    subgraph s4[split];
      d0["split string at newline"] --> d1["save after newline to stored buffer"];
      d1 --> d2["return line (string to newline)"];
    end s4;
    b1 --Yes--> a0;
    s1 --Yes--> a0;
    s1 --No--> b0;
    a0 -->|No|b0;
    a1 --> d0;
  end;
```

## gnl_test.sh

when you run this shell script, 

First, compile will start with BUFFER_SIZE = 0,and will return NULL.

After that, compile with BUFFER_SIZE = 1, 42, 1024 will test by 14 txt files.

These tests outputs "cat {file}", then outputs "./a.out {file}".

Compare both outputs.

## gnl_main.c
gnl_main.c includes cases fd=0 and multi fds Comment-Outed.

## make
make b0 compiles with BUFFER_SIZE=0.

make b1 compiles with BUFFER_SIZE=1.

make b2 compiles with BUFFER_SIZE=42.

make b3 compiles with BUFFER_SIZE=1024.
