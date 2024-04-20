use std::{io::{stdin,stdout,Write,BufWriter, Read}};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  //let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);

  let mut n = input.trim().parse::<i64>().unwrap();

  writeln!(out,"{}\n{}",n*n,2);
}