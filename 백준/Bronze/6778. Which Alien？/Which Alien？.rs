use std::{io::{stdin,stdout,Write,BufWriter, Read}};

fn main() {
  let stdout = stdout();
  let mut out = BufWriter::new(stdout.lock());
  
  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let a = input.trim().parse::<i64>().unwrap();

  let mut input = String::new();
  stdin().read_line(&mut input).unwrap();
  let b = input.trim().parse::<i64>().unwrap();

  if a>=3&&b<=4{
    writeln!(out,"TroyMartian");
  }
  
  if a<=6&&b>=2{
    writeln!(out,"VladSaturnian");
  }

  if a<=2&&b<=3{
    writeln!(out,"GraemeMercurian");
  }
}