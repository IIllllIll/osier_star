use std::{io::{stdin,stdout,Write,BufWriter, Read}};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let mut n = input.trim().parse::<i64>().unwrap();

  while n>0 {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

    let x = input.next().unwrap();
    let y = input.next().unwrap();

    if x>=y{
      writeln!(out,"MMM BRAINS");
    } 
    else {
      writeln!(out,"NO BRAINS");
    }
    n-=1;
  }
}