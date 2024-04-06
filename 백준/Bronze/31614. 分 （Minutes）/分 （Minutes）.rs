use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let h = input.trim().parse::<i64>().unwrap();

  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let m = input.trim().parse::<i64>().unwrap();

  write!(out,"{}",(60*h)+m);
}