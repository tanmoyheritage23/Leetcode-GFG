class Room {
    int roomId;
    long endTime;

    Room(int roomId, long endTime) {
        this.roomId = roomId;
        this.endTime = endTime;
    }
}

class Solution {
    public int mostBooked(int n, int[][] meetings) {

        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);

        // available rooms (min room id first)
        PriorityQueue<Integer> freeRooms = new PriorityQueue<>();

        // busy rooms (min end time first, tie → smaller roomId)
        PriorityQueue<Room> busyRooms = new PriorityQueue<>(
            (a, b) -> {
                if (a.endTime != b.endTime)
                    return Long.compare(a.endTime, b.endTime);
                return a.roomId - b.roomId;
            }
        );

        for (int i = 0; i < n; i++) {
            freeRooms.offer(i);
        }

        int[] count = new int[n];

        for (int[] meeting : meetings) {
            long start = meeting[0];
            long end = meeting[1];
            long duration = end - start;

            // release finished rooms
            while (!busyRooms.isEmpty() && busyRooms.peek().endTime <= start) {
                freeRooms.offer(busyRooms.poll().roomId);
            }

            int roomId;

            // if room is free → pick smallest id
            if (!freeRooms.isEmpty()) {
                roomId = freeRooms.poll();
                busyRooms.offer(new Room(roomId, end));
            }
            // else delay
            else {
                Room room = busyRooms.poll();
                roomId = room.roomId;
                busyRooms.offer(new Room(roomId, room.endTime + duration));
            }

            count[roomId]++;
        }

        // find result
        int best = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[best]) best = i;
        }

        return best;
    }
}