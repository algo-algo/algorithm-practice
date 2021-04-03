package sw;

import java.io.FileInputStream;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Num5648 {
    static class Solution {
        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/5648_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                int N = sc.nextInt(); // 원자들의 수

                List<Atom> atoms = new ArrayList<>();
                for (int i = 0; i < N; i++) {
                    float x = sc.nextFloat();
                    float y = sc.nextFloat();
                    int direction = sc.nextInt();
                    int energy = sc.nextInt();
                    atoms.add(new Atom(new Position(x, y), direction, energy));
                }


                AtomicInteger energySum = new AtomicInteger();

                while (!atoms.isEmpty()) {
                    // 움직인다.
                    atoms.forEach(Atom::move);

                    // -1000 <= x, y <= 1000 을 벗어난 범위의 원자가 있으면 배열에서 제거한다.
                    atoms.removeIf(Atom::isNotValidRange);

                    // 원자들 중 충돌한 원자가 있는지 검사한다.
                    Set<Atom> deleteAtoms = new HashSet<>();

                    for (int atomIndex = 0; atomIndex < atoms.size(); atomIndex++) {
                        Atom standardAtom = atoms.get(atomIndex);
                        if (!deleteAtoms.contains(standardAtom)) {
                            for (int compareIndex = atomIndex + 1; compareIndex < atoms.size(); compareIndex++) {
                                Atom compareAtom = atoms.get(compareIndex);
                                if (!standardAtom.equals(compareAtom)
                                        && !deleteAtoms.contains(compareAtom)
                                        && standardAtom.isSamePosition(compareAtom)) {
                                    deleteAtoms.add(standardAtom);
                                    deleteAtoms.add(compareAtom);
                                }
                            }
                        }
                    }

                    // 충돌한 원자가 있다면 에너지를 답에 더해주고 원자를 제거한다.
                    deleteAtoms.forEach(atom -> {
                        energySum.addAndGet(atom.getEnergy());
                        atoms.remove(atom);
                    });
                }

                System.out.println("#" + test_case + " " + energySum);
            }
        }
    }

    static class Atom {
        private Position position;
        private final int direction;
        private final int energy;

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

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Atom atom = (Atom) o;
            return direction == atom.direction && energy == atom.energy && Objects.equals(position, atom.position);
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
