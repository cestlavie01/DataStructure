/*
 * Introduce.h
 *
 *  Created on: 2016. 8. 15.
 *      Author: cobus
 */

#ifndef TREE_INTRODUCE_H_
#define TREE_INTRODUCE_H_

/**
 * tree관련 용어
 * 		node
 * 			tree의 구성 요소.
 * 		edge
 * 			node - node를 연결하는
 * 		root node
 * 			tree 최상위에 위치한 node
 * 		terminal node (leaf node)
 * 			tree의 마지막에 위치한 node
 * 		internal node
 * 			terminal node를 제외한 node
 * 		Empty Set
 * 			node가 위치할 수 있는 곳에 node가 존재하지 않는 경우,
 * 			Emptry Set이 있는것으로 간주한다.
 * 			a -- b -- d       a -- b -- d -- Empty
 * 			  -- c -- e   =>              -- Empty
 * 			       -- f -            -- c -- e -- Empty
 * 			                                   -- Empty
 * 			                              -- f -- Empty
 * 			                                   -- Empty
 * 		SubTree
 * 			http://algorithms.tutorialhorizon.com/files/2014/09/Tree-is-subtree-of-another-tree-example.png
 *
 * tree 유형
 * 		포화 이진 트리 (Full Binary Tree)
 * 			tree의 node가 꽉찬 상태여서, 하나의 node를 추가할 때,
 * 			새로운 레벨이 필요한 경우.
 *
 * 		완전 이진 트리 (Complete Binary Tree)
 * 			node를 추가할 때, 새로운 level에 필요하지는 않지만,
 * 			부모 node와 자식 node가 모두 1:2관계를 유지하고 있는 상태.
 *
 * 이진 탐색 트리 순회 (Traversal)
 * 		http://cfile25.uf.tistory.com/image/2628544554ED8E6E0658DC
 * 		전위
 * 			정렬이 되어있는 tree라면, 오름차순으로 순회.
 * 		중위
 * 			순회하는 부모 노드 우선 출력.
 * 		후위
 * 			정렬이 되어있는 tree라면, 내림차순으로 순회.
 */

#endif /* TREE_INTRODUCE_H_ */
