open Sys;;
open String;;
open List;;
open Array;;
open Str;;
open Printf;;

let prints x = print_string(x ^ "\n");;

let ft_concat path file = path ^ file;;

let ft_out file message =
	let oc = open_out file in    (* create or truncate file, return channel *)
		fprintf oc "%s\n" message;   (* write something *)
		close_out oc
;;

let ft_in filename =
	let lines = ref [] in
		let chan = open_in filename in
		try
			while true; do
				lines := input_line chan :: !lines
			done; []
		with e ->
			close_in chan;
			List.rev !lines
;;

let init () =
	let check file =
		if file = "./src/" then
			let concat file = ft_concat("./src/")(file) in
			Array.iter(Sys.remove)(Array.map(concat)(Sys.readdir(file))) in
	Array.iter(check)(Sys.readdir("."))
;;

let ft_read () =
	let folder = "./inc/" in
		let inclist = Sys.readdir(folder) in
			let clist = Array.map(ft_concat(folder))(inclist) in
				Array.map(ft_in) clist
;;

let ft_write () =
	let f x = List.map(String.trim)(x) in
		let arra = Array.map(f)(ft_read()) in

	let test = Str.regexp(".*struct.*") in
		let print_test s = if (string_match(test)(s)(0))
			then prints(s) in
			let g x = List.iter(print_test)(x) in
				Array.iter(g)(arra);
;;

init();;
ft_write();;

(* let g x = List.map(String.trim)(x) in
	Array.map(g)(ft_read())
;;
 *)
