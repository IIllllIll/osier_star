use std::{io::{stdin,stdout,Write,BufWriter, Read}, fmt::write};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let a = input.trim().parse::<i64>().unwrap();

  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let b = input.trim().parse::<i64>().unwrap();
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let c = input.trim().parse::<i64>().unwrap();
  
  write!(out,"{}",(a*b)+c);
}