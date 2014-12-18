open Sys;;
open Array;;
open Printf;;

let prints x = print_string(x ^ "\n");;

let ft_out file message =
	let oc = open_out file in    (* create or truncate file, return channel *)
		fprintf oc "%s\n" message;   (* write something *)
		close_out oc
;;

let ft_in file =
	let ic = open_in file in
		try
			let line = input_line ic in  (* read line from in_channel and discard \n *)
			print_endline line;          (* write the result to stdout *)

		with e ->                      (* some unexpected exception occurs *)
			close_in_noerr ic;           (* emergency closing *)
			raise e                      (* exit with error: files are closed but
                                    channels are not flushed *)
;;

let ft_in file =
	let ic = open_in file in
		let ft_input_line i = input_line ic in
			Array.init(3)(ft_input_line)
;;

let read_file filename =
let lines = ref [] in
let chan = open_in filename in
try
  while true; do
    lines := input_line chan :: !lines
  done; []
with End_of_file ->
  close_in chan;
  List.rev !lines ;;

let init () =
	let check file =
		if file = "src" then
			let concat file = "./src/" ^ file in
			Array.iter(Sys.remove)(Array.map(concat)(Sys.readdir(file))) in
	Array.iter(check)(Sys.readdir("."))
;;

let test () =
	let folder = "./inc" in
	let list = Sys.readdir(folder) in
		Array.iter(prints)(list)
;;

let () =
	init();
	test();
;;

open List;;

List.iter(prints)(read_file "inc/header1.h");;
(*
out("src/test.c")("Hello");;
 *)
