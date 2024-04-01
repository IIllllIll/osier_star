use std::io::{stdin,stdout,Write,BufWriter};

fn main() {
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i64>);


  let a = input.next().unwrap();
  let b = input.next().unwrap();

  println!("{}",a*b);
}