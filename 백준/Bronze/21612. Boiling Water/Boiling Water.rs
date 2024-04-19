use std::{io::{stdin,stdout,Write,BufWriter, Read}};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  
  let n = input.trim().parse::<i64>().unwrap();

  writeln!(out,"{}",(5*n)-400);

  if (5*n)-400<100{
    writeln!(out,"1");
  }
  else if (5*n)-400==100{
    writeln!(out,"0");
  }
  else{
    writeln!(out,"-1");
  }
}