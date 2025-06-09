function [next_state, motor_cmd] = micromouse_controller(state, sensors, pos, heading, goal)
% Main controller entry function
% Inputs:
%   state   - current FSM state
%   sensors - [wall_left, wall_front, wall_right] binary sensor values
%   pos     - current grid position [x, y]
%   heading - current heading (0=N, 90=E, 180=S, 270=W)
%   goal    - goal position [x, y]
%
% Outputs:
%   next_state - new FSM state
%   motor_cmd  - [left_motor_pwm, right_motor_pwm]

% Unpack sensor inputs
wall_left = sensors(1);
wall_front = sensors(2);
wall_right = sensors(3);

% Delegate to state logic
[next_state, motor_cmd] = state_logic(state, wall_left, wall_front, wall_right, pos, heading, goal);
end
