use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let a = input.next().unwrap();
  let b = input.next().unwrap();
  let c = input.next().unwrap();

  if a+b==c{
    write!(out,"correct!");
  }
  else{
    write!(out,"wrong!");
  }
}