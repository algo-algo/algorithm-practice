package sw;

import java.io.FileInputStream;
import java.util.*;

public class Num5648Two {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/5648_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int N = sc.nextInt(); // 원자들의 수

                Map<Integer, Atom> atoms = new HashMap<>();
                for (int i = 0; i < N; i++) {
                    float x = sc.nextFloat();
                    float y = sc.nextFloat();
                    int direction = sc.nextInt();
                    int energy = sc.nextInt();
                    atoms.put(i, new Atom(new Position(x, y), direction, energy));
                }

                for (int i = 0; i < atoms.size(); i++) {
                    Atom standard = atoms.get(i);
                    for (int j = 0; j < atoms.size(); j++) {
                        standard.isHit(atoms.get(j), j);
                    }
                }

                // 만날 일이 없는 원자는 미리 삭제한다.
                atoms.values().removeIf(Atom::noHitAtom);

                int[] energySum = {0};

                while (!atoms.isEmpty()) {
                    // 움직인다.
                    atoms.values().forEach(Atom::move);

                    // -1000 <= x, y <= 1000 을 벗어난 범위의 원자가 있으면 배열에서 제거한다.
                    atoms.values().removeIf(Atom::isNotValidRange);

                    // 충돌 확인해서 제거하기
                    iterateAtomDelete(atoms, energySum);
                }

                System.out.println("#" + test_case + " " + energySum[0]);
            }
        }

        private static void iterateAtomDelete(Map<Integer, Atom> atoms, int[] energySum) {
            Set<Integer> atomIndexes = new HashSet<>(atoms.keySet());
            for (Integer atomIndex : atomIndexes) {
                if (atoms.containsKey(atomIndex)) {
                    Atom standard = atoms.get(atomIndex);
                    List<Integer> hitAtomCandidates = standard.getHitAtomCandidates();
                    boolean isDelete = false;
                    for (Integer compareIndex : hitAtomCandidates) {
                        if (atoms.containsKey(compareIndex)) {
                            Atom compare = atoms.get(compareIndex);
                            if (standard.isSamePosition(compare)) {
                                energySum[0] += compare.getEnergy();
                                atoms.remove(compareIndex);
                                isDelete = true;
                            }
                        }
                    }
                    if (isDelete) {
                        energySum[0] += standard.getEnergy();
                        atoms.remove(atomIndex);
                    }
                }
            }
        }

        static class Atom {
            private Position position;
            private final int direction;
            private final int energy;
            private final List<Integer> hitAtomCandidates = new ArrayList<>();

            public Atom(Position position, int direction, int energy) {
                this.position = position;
                this.direction = direction;
                this.energy = energy;
            }

            public void move() {
                this.position.move(this.direction);
            }

            public boolean isNotValidRange() {
                return !this.position.isValidRange();
            }

            public int getEnergy() {
                return energy;
            }

            public boolean isSamePosition(Atom atom) {
                return Objects.equals(position, atom.position);
            }

            public void isHit(Atom atom, int index) {
                Position targetPosition = atom.position;
                int targetDirection = atom.direction;
                if (position.x == targetPosition.x && position.y < targetPosition.y) {
                    if (direction == 0 && targetDirection == 1) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x == targetPosition.x && position.y > targetPosition.y) {
                    if (direction == 1 && targetDirection == 0) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x < targetPosition.x && position.y == targetPosition.y) {
                    if (direction == 3 && targetDirection == 2) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x > targetPosition.x && position.y == targetPosition.y) {
                    if (direction == 2 && targetDirection == 3) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x < targetPosition.x && position.y < targetPosition.y) {
                    if ((direction == 0 && targetDirection == 2)
                            || (direction == 3 && targetDirection == 1)) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x > targetPosition.x && position.y < targetPosition.y) {
                    if ((direction == 0 && targetDirection == 3)
                            || (direction == 2 && targetDirection == 1)) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x > targetPosition.x && position.y > targetPosition.y) {
                    if ((direction == 1 && targetDirection == 3)
                            || (direction == 2 && targetDirection == 0)) {
                        hitAtomCandidates.add(index);
                    }
                } else if (position.x < targetPosition.x && position.y > targetPosition.y) {
                    if ((direction == 1 && targetDirection == 2)
                            || (direction == 3 && targetDirection == 0)) {
                        hitAtomCandidates.add(index);
                    }
                }
            }

            public boolean noHitAtom() {
                return hitAtomCandidates.isEmpty();
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Atom atom = (Atom) o;
                return direction == atom.direction && energy == atom.energy && Objects.equals(position, atom.position);
            }

            public List<Integer> getHitAtomCandidates() {
                return hitAtomCandidates;
            }
        }

        static class Position {
            private float x;
            private float y;

            public Position(float x, float y) {
                this.x = x;
                this.y = y;
            }

            public void move(int direction) {
                switch (direction) {
                    case 0:
                        this.y += 0.5f;
                        break;
                    case 1:
                        this.y -= 0.5f;
                        break;
                    case 2:
                        this.x -= 0.5f;
                        break;
                    case 3:
                        this.x += 0.5f;
                        break;
                    default:
                        break;
                }
            }

            public boolean isValidRange() {
                return -1000 <= this.x && this.x <= 1000
                        && -1000 <= this.y && this.y <= 1000;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Position position = (Position) o;
                return Float.compare(position.x, x) == 0 && Float.compare(position.y, y) == 0;
            }

            @Override
            public int hashCode() {
                return Objects.hash(x, y);
            }
        }
    }
}
